/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

static const uint32_t STM32C071G8_flash_prog_blob[] = {
    0xE00ABE00,
    0x4811b672, 0x60814911, 0x03c96981, 0x68c1d504, 0xd4122900, 0x47702000, 0x4a0e490d, 0x4a0e600a,
    0x2206600a, 0x4a0d604a, 0x490d608a, 0x604a4a0d, 0x600a227f, 0x290068c1, 0x490bd5ec, 0x490b6001,
    0x20006001, 0x46c04770, 0x40022008, 0x0000c3fa, 0x40003000, 0x0000aaaa, 0x00005555, 0x00000fff,
    0x40002c00, 0x000001ff, 0x45670123, 0xcdef89ab, 0x07c02001, 0x680a4902, 0x600a4302, 0x47702000,
    0x40022014, 0x47702001, 0xb672b5b0, 0x04032001, 0x1f0a490c, 0x421c6814, 0x680dd1fb, 0x43252404,
    0x680d600d, 0x600d431d, 0x421d6815, 0x6815d1fc, 0x421d4b05, 0x6013d001, 0x6808bdb0, 0x600843a0,
    0xbdb02000, 0x40022014, 0x0000c3fa, 0xb672b5f0, 0x680c491a, 0x1f0a491a, 0x60134b1a, 0x4d1a00a4,
    0x24074025, 0x680c1b65, 0x600c402c, 0x06e4241f, 0x0a001900, 0x4304680c, 0x43342602, 0x2001600c,
    0x680f0404, 0x600f4327, 0x42276817, 0x6817d1fc, 0xd001421f, 0xbdf06013, 0x40286808, 0x68086008,
    0x600843b0, 0x06c02001, 0x20006802, 0xd0001c52, 0x3914bdf0, 0x4322680a, 0xbdf0600a, 0x1fff75a0,
    0x40022014, 0x0000c3fa, 0x00003ff8, 0xb08ab5f0, 0xb6724603, 0x20011dce, 0x04049000, 0x68084929,
    0xd1fc4220, 0x60084828, 0x9d006848, 0x60484328, 0x43862007, 0x3080a802, 0xe0029001, 0x07c06808,
    0x2e00d12a, 0x2e07d02d, 0x6815d90a, 0x6855601d, 0x3208605d, 0x4225680d, 0x3e08d1fc, 0xe7ed3308,
    0x4635af02, 0xc7017810, 0x1c521e6d, 0xd1f92d00, 0xd0072e08, 0xaf0200b5, 0x3e08197d, 0xc50120ff,
    0xd3fb1c76, 0x42206808, 0x9802d1fc, 0x98016018, 0x60586800, 0xe7d12600, 0x6008480c, 0xb00a9800,
    0x684abdf0, 0x439a2301, 0x06da604a, 0x20006812, 0xd0041c52, 0x3910041b, 0x439a680a, 0xb00a600a,
    0x46c0bdf0, 0x40022010, 0x000001ff, 0x0000c3fa, 0x00000000};

// Start address of flash
static const uint32_t flash_start = 0x08000000;
// Size of flash
static const uint32_t flash_size = 0x00010000;

/**
 * List of start and size for each size of flash sector - even indexes are start, odd are size
 * The size will apply to all sectors between the listed address and the next address
 * in the list.
 * The last pair in the list will have sectors starting at that address and ending
 * at address flash_start + flash_size.
 */
static const uint32_t sectors_info[] = {
    0x08000000,
    0x00000800,
};

static const program_target_t flash = {
    0x20000005,  // Init
    0x20000075,  // UnInit
    0x2000008d,  // EraseChip
    0x200000d1,  // EraseSector
    0x20000151,  // ProgramPage
    0x120000003, // Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x20000001,
        0x20000214,
        0x20000500},

    0x20000000 + 0x00000A00,             // mem buffer location
    0x20000000,                          // location to write prog_blob in target RAM
    sizeof(STM32C071G8_flash_prog_blob), // prog_blob size
    STM32C071G8_flash_prog_blob,         // address of prog_blob
    0x00000800                           // ram_to_flash_bytes_to_be_written
};
