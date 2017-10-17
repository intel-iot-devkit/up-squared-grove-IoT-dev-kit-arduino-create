/*
 * Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file PubSub.cpp
 * @brief Sample demonstrating MQTT operations
 *
 */
/*********************************PRE-REQUISITES**************************************
 * This sample needs credentials and keys obtained from AWS.
 * Follow the instructions here to get the 
 * https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/examples/PubSub/README.md
 * Setup the portal and update the sample. Setup monitoring on AWS before running the sample.
 *
 **************************************************************************************/
#include <chrono>
#include <cstring>
#include <regex>

#include "aws-iot-device-sdk-cpp.h"
#include "util/logging/Logging.hpp"
#include "util/logging/LogMacros.hpp"
#include "util/logging/ConsoleLogSystem.hpp"

#include "Arduino.h"
#include "PubSub.hpp"
#include "arduino_secrets.h"

#define LOG_TAG_PUBSUB "[Sample - PubSub]"
#define MESSAGE_COUNT 5

//The topic to which the device publishes
#define SDK_SAMPLE_TOPIC "sdk/test/cpp"
#define ENDPOINT "a3b46xnzlex21u.iot.us-west-2.amazonaws.com"
#define CLIENT_ID "Thing-01"
#define THING_NAME "Thing-01"
#define AWS_ACCESS_KEY_ID ""
#define AWS_ACCESS_KEY ""
#define DEFAULTSAMPLECONFIG "{  \"endpoint\": \"" ENDPOINT "\",  \"mqtt_port\": 8883,  \"https_port\": 443,  \"greengrass_discovery_port\": 8443,  \"root_ca_relative_path\": \"rootCA.pem\",  \"device_certificate_relative_path\": \"34534543-certificate.pem.crt\",  \"device_private_key_relative_path\": \"234234234-private.pem.key\",  \"tls_handshake_timeout_msecs\": 60000,  \"tls_read_timeout_msecs\": 2000,  \"tls_write_timeout_msecs\": 2000,  \"aws_region\": \"us-west-2\",  \"aws_access_key_id\": \"" AWS_ACCESS_KEY_ID "\",  \"aws_secret_access_key\": \"" AWS_ACCESS_KEY "\",  \"aws_session_token\": \"\",  \"client_id\": \"" CLIENT_ID "\",  \"thing_name\": \"" THING_NAME "\",  \"is_clean_session\": true,  \"mqtt_command_timeout_msecs\": 20000,  \"keepalive_interval_secs\": 30,  \"minimum_reconnect_interval_secs\": 1,  \"maximum_reconnect_interval_secs\": 128,  \"maximum_acks_to_wait_for\": 32,  \"action_processing_rate_hz\": 5,  \"maximum_outgoing_action_queue_length\": 32,  \"discover_action_timeout_msecs\": 300000, \"load_crts_as_strings\": true }"
std::string clientCertString;
std::string clientKeyString; 
std::string rootCAString ;
/* This sample needs the Root CA, Device Private Certificate and the device private key.
This can be provided in three ways.
    1. By using the secret tab to provide the string value. The value should be formatted
    to be of format
    "-----BEGIN CERTIFICATE-----\nMIIE0zCCA7ugAwIBAgIQGNrRniZ96LtKIVjNzGs7SjANBgkqhki\n...."
    This format can be done manually
    or by using the unix command : awk 'NF {sub(/\r/, ""); printf "%s\\n",$0;}' cert-name.pem
    or by using the helper function : formatCertString as is the default behavior of this sample.

    2. By putting the certificate files on the device and updating the file name in
    sample config value. This is the most secure way and recommended for production. The Sample

    2. By providing inline
    const char* rootCAString =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIE0zCCA7ugAwIBAgIQGNrRniZ96LtKIVjNzGs7SjANBgkqhkiG9w0BAQUFADCB\n"
    .
    .
    "hnacRHr2lVz2XTIIM6RUthg/aFzyQkqFOFSDX9HoLPKsEdao7WNq\n"
    "-----END CERTIFICATE-----";
*/


namespace awsiotsdk {
    namespace samples {
        ResponseCode PubSub::RunPublish(int msg_count) {
            std::cout << std::endl
                      << "******************************Entering Publish with no queuing delay unless queue is full!!**************************"
                      << std::endl;
            ResponseCode rc;
            uint16_t packet_id = 0;
            int itr = 1;

            util::String p_topic_name_str = SDK_SAMPLE_TOPIC;

            double angle = 0;
            do {
                //read value of A0
                angle = analogRead(512);
                util::String payload = std::to_string(angle);
                std::cout << "Publish Payload : " << payload << std::endl;

                std::unique_ptr<Utf8String> p_topic_name = Utf8String::Create(p_topic_name_str);
                rc = p_iot_client_->PublishAsync(std::move(p_topic_name), false, false, mqtt::QoS::QOS1,
                                                 payload, nullptr, packet_id);
                if (ResponseCode::SUCCESS == rc) {
                    cur_pending_messages_++;
                    total_published_messages_++;
                    std::cout << "Publish Packet Id : " << packet_id << std::endl;
                } else if (ResponseCode::ACTION_QUEUE_FULL == rc) {
                    itr--;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
            } while (++itr <= msg_count && (ResponseCode::SUCCESS == rc || ResponseCode::ACTION_QUEUE_FULL == rc));

            return rc;
        }

        ResponseCode PubSub::SubscribeCallback(util::String topic_name,
                                               util::String payload,
                                               std::shared_ptr<mqtt::SubscriptionHandlerContextData> p_app_handler_data) {
            std::cout << std::endl << "************" << std::endl;
            std::cout << "Received message on topic : " << topic_name << std::endl;
            std::cout << "Payload Length : " << payload.length() << std::endl;
            if (payload.length() < 50) {
                std::cout << "Payload : " << payload << std::endl;
            }
            std::cout << std::endl << "************" << std::endl;
            cur_pending_messages_--;
            return ResponseCode::SUCCESS;
        }

        ResponseCode PubSub::DisconnectCallback(util::String client_id,
                                                std::shared_ptr<DisconnectCallbackContextData> p_app_handler_data) {
            std::cout << "*******************************************" << std::endl
                      << client_id << " Disconnected!" << std::endl
                      << "*******************************************" << std::endl;
            return ResponseCode::SUCCESS;
        }

        ResponseCode PubSub::Subscribe() {
            util::String p_topic_name_str = SDK_SAMPLE_TOPIC;
            std::unique_ptr<Utf8String> p_topic_name = Utf8String::Create(p_topic_name_str);
            mqtt::Subscription::ApplicationCallbackHandlerPtr p_sub_handler = std::bind(&PubSub::SubscribeCallback,
                                                                                        this,
                                                                                        std::placeholders::_1,
                                                                                        std::placeholders::_2,
                                                                                        std::placeholders::_3);
            std::shared_ptr<mqtt::Subscription> p_subscription =
                mqtt::Subscription::Create(std::move(p_topic_name), mqtt::QoS::QOS0, p_sub_handler, nullptr);
            util::Vector<std::shared_ptr<mqtt::Subscription>> topic_vector;
            topic_vector.push_back(p_subscription);

            ResponseCode rc = p_iot_client_->Subscribe(topic_vector, ConfigCommon::mqtt_command_timeout_);
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return rc;
        }

        ResponseCode PubSub::Unsubscribe() {
            util::String p_topic_name_str = SDK_SAMPLE_TOPIC;
            std::unique_ptr<Utf8String> p_topic_name = Utf8String::Create(p_topic_name_str);
            util::Vector<std::unique_ptr<Utf8String>> topic_vector;
            topic_vector.push_back(std::move(p_topic_name));

            ResponseCode rc = p_iot_client_->Unsubscribe(std::move(topic_vector), ConfigCommon::mqtt_command_timeout_);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return rc;
        }

        ResponseCode PubSub::InitializeTLS() {
            ResponseCode rc = ResponseCode::SUCCESS;

            std::shared_ptr<network::OpenSSLConnection> p_network_connection =
                std::make_shared<network::OpenSSLConnection>(ConfigCommon::endpoint_,
                                                             ConfigCommon::endpoint_mqtt_port_,
                                                             rootCAString.c_str(),
                                                             clientCertString.c_str(),
                                                             clientKeyString.c_str(),
                                                             ConfigCommon::tls_handshake_timeout_,
                                                             ConfigCommon::tls_read_timeout_,
                                                             ConfigCommon::tls_write_timeout_, true, ConfigCommon::load_crts_as_strings_);
            rc = p_network_connection->Initialize();

            if (ResponseCode::SUCCESS != rc) {
                AWS_LOG_ERROR(LOG_TAG_PUBSUB,
                              "Failed to initialize Network Connection. %s",
                              ResponseHelper::ToString(rc).c_str());
                rc = ResponseCode::FAILURE;
            } else {
                p_network_connection_ = std::dynamic_pointer_cast<NetworkConnection>(p_network_connection);
            }
            return rc;
        }

        ResponseCode PubSub::RunSample() {
            total_published_messages_ = 0;
            cur_pending_messages_ = 0;

            ResponseCode rc = InitializeTLS();
            if (ResponseCode::SUCCESS != rc) {
                return rc;
            }

            ClientCoreState::ApplicationDisconnectCallbackPtr p_disconnect_handler =
                std::bind(&PubSub::DisconnectCallback, this, std::placeholders::_1, std::placeholders::_2);

            p_iot_client_ = std::shared_ptr<MqttClient>(MqttClient::Create(p_network_connection_,
                                                                           ConfigCommon::mqtt_command_timeout_,
                                                                           p_disconnect_handler, nullptr));
            if (nullptr == p_iot_client_) {
                return ResponseCode::FAILURE;
            }

            util::String client_id_tagged = ConfigCommon::base_client_id_;
            client_id_tagged.append("_pub_sub_tester_");
            client_id_tagged.append(std::to_string(rand()));
            std::unique_ptr<Utf8String> client_id = Utf8String::Create(client_id_tagged);

            rc = p_iot_client_->Connect(ConfigCommon::mqtt_command_timeout_, ConfigCommon::is_clean_session_,
                                        mqtt::Version::MQTT_3_1_1, ConfigCommon::keep_alive_timeout_secs_,
                                        std::move(client_id), nullptr, nullptr, nullptr);
            if (ResponseCode::MQTT_CONNACK_CONNECTION_ACCEPTED != rc) {
                return rc;
            }

            rc = Subscribe();
            if (ResponseCode::SUCCESS != rc) {
                AWS_LOG_ERROR(LOG_TAG_PUBSUB, "Subscribe failed. %s", ResponseHelper::ToString(rc).c_str());
            } else {
                // Test with delay between each action being queued up
                rc = RunPublish(MESSAGE_COUNT);
                if (ResponseCode::SUCCESS != rc) {
                    std::cout << std::endl << "Publish runner failed. " << ResponseHelper::ToString(rc) << std::endl;
                    AWS_LOG_ERROR(LOG_TAG_PUBSUB, "Publish runner failed. %s",
                                  ResponseHelper::ToString(rc).c_str());
                    p_iot_client_->Disconnect(ConfigCommon::mqtt_command_timeout_);
                }

                std::cout << ResponseHelper::ToString(rc) << std::endl;
                if (ResponseCode::SUCCESS == rc) {
                    //Sleep for 10 seconds and wait for all messages to be received
                    int cur_sleep_sec_count = 0;
                    do {
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        if (0 == cur_pending_messages_) {
                            break;
                        }
                        cur_sleep_sec_count++;
                        std::cout << "Waiting!!! " << cur_sleep_sec_count << std::endl;
                    } while (cur_sleep_sec_count < 100);
                }

                do {
                    rc = Unsubscribe();
                    if (ResponseCode::ACTION_QUEUE_FULL == rc) {
                        std::cout << "Message queue full on Unsub, waiting!!!" << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    }
                } while (ResponseCode::ACTION_QUEUE_FULL == rc);
                if (ResponseCode::SUCCESS != rc) {
                    AWS_LOG_ERROR(LOG_TAG_PUBSUB, "Unsubscribe failed. %s",
                                  ResponseHelper::ToString(rc).c_str());
                }
            }

            rc = p_iot_client_->Disconnect(ConfigCommon::mqtt_command_timeout_);
            if (ResponseCode::SUCCESS != rc) {
                AWS_LOG_ERROR(LOG_TAG_PUBSUB, "Disconnect failed. %s", ResponseHelper::ToString(rc).c_str());
            }

            std::cout << std::endl << "*************************Results**************************" << std::endl;
            std::cout << "Pending published messages : " << cur_pending_messages_ << std::endl;
            std::cout << "Total published messages : " << total_published_messages_ << std::endl;
            std::cout << "Exiting Sample!!!!" << std::endl;
            return ResponseCode::SUCCESS;
        }
    }
}

void setup() {
    //add the Grove Pi+ sub-platform
    mraa_add_subplatform(MRAA_GROVEPI, "0");

    //Convert the certificate strings to be compatible with SSL
    const auto targetCrt = std::regex{" (?!CERTIFICATE)"};
    const auto replacement = "\n";
    rootCAString = std::regex_replace(SECRET_ROOT_CA, targetCrt, replacement);
    clientCertString = std::regex_replace(SECRET_CLIENT_CERT, targetCrt, replacement);
    const auto targetKey = std::regex{" (?!RSA)(?!PRIVATE)(?!KEY)"};
    clientKeyString = std::regex_replace(SECRET_CLIENT_PRIVATE_KEY, targetKey, replacement);

    std::shared_ptr<awsiotsdk::util::Logging::ConsoleLogSystem> p_log_system =
        std::make_shared<awsiotsdk::util::Logging::ConsoleLogSystem>(awsiotsdk::util::Logging::LogLevel::Info);
    awsiotsdk::util::Logging::InitializeAWSLogging(p_log_system);

    std::unique_ptr<awsiotsdk::samples::PubSub>
        pub_sub = std::unique_ptr<awsiotsdk::samples::PubSub>(new awsiotsdk::samples::PubSub());
    const char* defaultSampleConfig = (const char*) DEFAULTSAMPLECONFIG;
    //Or use awsiotsdk::ResponseCode rc = awsiotsdk::ConfigCommon::InitializeCommon("SampelConfig.json");
    awsiotsdk::ResponseCode rc = awsiotsdk::ConfigCommon::InitializeCommon(defaultSampleConfig);
    if (awsiotsdk::ResponseCode::SUCCESS == rc) {
        rc = pub_sub->RunSample();
    }
#ifdef WIN32
    std::cout<<"Press any key to continue!!!!"<<std::endl;
    getchar();
#endif

    awsiotsdk::util::Logging::ShutdownAWSLogging();
}
void loop(){
  delay(100);
}
