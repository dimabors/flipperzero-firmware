#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <lib/flipper_format/flipper_format.h>
#include "furi.h"
#include "furi_hal.h"
#include <lib/subghz/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WSBlockGeneric WSBlockGeneric;

struct WSBlockGeneric {
    const char* protocol_name;
    uint64_t data;
    uint32_t id;
    uint8_t data_count_bit;
    uint8_t battery_low;
    uint8_t humidity;
    uint8_t channel;
    uint8_t btn;
    float temp;
};

/**
 * Get name preset.
 * @param preset_name name preset
 * @param preset_str Output name preset
 */
void ws_block_generic_get_preset_name(const char* preset_name, FuriString* preset_str);

/**
 * Serialize data WSBlockGeneric.
 * @param instance Pointer to a WSBlockGeneric instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param preset The modulation on which the signal was received, SubGhzRadioPreset
 * @return true On success
 */
bool ws_block_generic_serialize(
    WSBlockGeneric* instance,
    FlipperFormat* flipper_format,
    SubGhzRadioPreset* preset);

/**
 * Deserialize data WSBlockGeneric.
 * @param instance Pointer to a WSBlockGeneric instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return true On success
 */
bool ws_block_generic_deserialize(WSBlockGeneric* instance, FlipperFormat* flipper_format);

float ws_block_generic_fahrenheit_to_celsius(float fahrenheit);

#ifdef __cplusplus
}
#endif