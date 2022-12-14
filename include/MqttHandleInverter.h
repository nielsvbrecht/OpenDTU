// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "Configuration.h"
#include <Arduino.h>
#include <Hoymiles.h>
#include <espMqttClient.h>
#include <memory>

class MqttHandleInverterClass {
public:
    void init();
    void loop();

    static String getTopic(std::shared_ptr<InverterAbstract> inv, uint8_t channel, uint8_t fieldId);

private:
    void publishField(std::shared_ptr<InverterAbstract> inv, uint8_t channel, uint8_t fieldId);
    void onMqttMessage(const espMqttClientTypes::MessageProperties& properties, const char* topic, const uint8_t* payload, size_t len, size_t index, size_t total);

    uint32_t _lastPublishStats[INV_MAX_COUNT];
    uint32_t _lastPublish;

    uint8_t _publishFields[14] = {
        FLD_UDC,
        FLD_IDC,
        FLD_PDC,
        FLD_YD,
        FLD_YT,
        FLD_UAC,
        FLD_IAC,
        FLD_PAC,
        FLD_F,
        FLD_T,
        FLD_PF,
        FLD_EFF,
        FLD_IRR,
        FLD_PRA
    };
};

extern MqttHandleInverterClass MqttHandleInverter;