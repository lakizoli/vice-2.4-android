/*
 * intl.c - Localization routines for Win32.
 *
 * Written by
 *  Marco van den Heuvel <blackystardust68@yahoo.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#include "archdep.h"
#include "cmdline.h"
#include "intl.h"
#include "lib.h"
#include "machine.h"
#include "res.h"
#include "resources.h"
#include "stringid.h"
#include "sysfile.h"
#include "translate.h"
#include "translate_languages.h"
#include "util.h"
#include "ui.h"
#include "winmain.h"

#ifdef __ANDROID__

#include "stringid.h"

typedef struct android_text_s {
	char* text_id;
	char* text;
} android_text_t;

// original and default ENGLISH text
static android_text_t android_text_en[] = {
	{ "IDS_VICE_ERROR", "VICE Error!" },
	{ "IDS_VICE_INFORMATION", "VICE Information" },
	{ "IDS_VICE_QUESTION", "VICE Question" },
	{ "IDS_FFMPEG_DLL_MISMATCH", "Your ffmpeg dll version doesn't match." },
	{ "IDS_DIRECTDRAW_ERROR", "DirectDraw error: Code:%8x Error:%s" },
	{ "IDS_CANNOT_SAVE_SETTINGS", "Cannot save settings." },
	{ "IDS_CANNOT_LOAD_SETTINGS", "Cannot load settings." },
	{ "IDS_DEFAULT_SETTINGS_RESTORED", "Default settings restored." },
	{ "IDS_CANNOT_ATTACH_FILE", "Cannot attach specified file" },
	{ "IDS_START_MONITOR", "%s\n\nStart monitor? (No will reset, cancel will continue)" },
	{ "IDS_VICE_CPU_JAM", "VICE CPU JAM" },
	{ "IDS_EXTEND_TO_40_TRACKS", "Extend image to 40-track format?" },
	{ "IDS_DETACHED_DEVICE_S", "Detached device %s" },
	{ "IDS_ATTACHED_S_TO_DEVICE_S", "Attached %s to device#%s" },
	{ "IDS_DETACHED_TAPE", "Detached tape" },
	{ "IDS_HISTORY_RECORDED_UNKNOWN", "History recorded with unknown release" },
	{ "IDS_HISTORY_RECORDED_VICE_S", "History recorded with VICE-%s" },
	{ "IDS_PAUSED", "paused" },
	{ "IDS_FRAME_NUMBER", "frame #" },
	{ "IDS_RESUMED", "resumed" },
	{ "IDS_REALLY_EXIT", "Do you really want to exit?\n\nAll the data present in the emulated RAM will be lost." },
	{ "IDS_TFE_PROBLEM", "TFE/RR-Net support is not available on your system,\nthere is some important part missing. Please have a\nlook at the VICE knowledge base support page\n\n      http://vicekb.trikaliotis.net/13-005\n\nfor possible reasons and to activate networking with VICE." },
	{ "IDS_TFE_RRNET_SUPPORT", "TFE/RR-Net support" },
	{ "IDS_CANNOT_AUTOSTART_FILE", "Cannot autostart specified file." },
	{ "IDS_ATTACHED_TAPE_S", "Attached tape %s" },
	{ "IDS_SETTINGS_SAVED_SUCCESS", "Settings saved successfully." },
	{ "IDS_SETTINGS_LOADED_SUCCESS", "Settings loaded successfully." },
	{ "IDS_ATTACH_DISK_IMAGE", "Attach disk image" },
	{ "IDS_ATTACH_TAPE_IMAGE", "Attach tape image" },
	{ "IDS_AUTOSTART_IMAGE", "Autostart disk/tape image" },
	{ "IDS_INVALID_CARTRIDGE", "Invalid cartridge image" },
	{ "IDS_BAD_CARTRIDGE_CONFIG", "Bad cartridge config in UI!" },
	{ "IDS_INVALID_CARTRIDGE_IMAGE", "Invalid cartridge image" },
	{ "IDS_LOG_CONSOLE_OUTPUT_IMAGE", "Logging console output image" },
	{ "IDS_LOG_FILES_TYPE", "VICE console logging files (*.dbg)" },
	{ "IDS_CANNOT_WRITE_LOGFILE_S", "Cannot write log file `%s'." },
	{ "IDS_LOAD_FLIP_LIST_FILE", "Load flip list file" },
	{ "IDS_CANNOT_READ_FLIP_LIST", "Cannot read flip list file" },
	{ "IDS_SAVE_FLIP_LIST_FILE", "Save flip list file" },
	{ "IDS_CANNOT_WRITE_FLIP_LIST", "Cannot write flip list file" },
	{ "IDS_SELECT_KEYMAP_FILE", "Select keymap file" },
	{ "IDS_SAVE_KEYMAP_FILE", "Save keymap file" },
	{ "IDS_CANNOT_WRITE_KEYMAP_FILE", "Cannot write keymap file" },
	{ "IDS_SAVE_CONFIG_FILE", "Save config file" },
	{ "IDS_LOAD_CONFIG_FILE", "Load config file" },
	{ "IDS_MAPPING", "Mapping" },
	{ "IDS_KEYBOARD_SETTINGS", "Keyboard settings" },
	{ "IDS_ATTACH", "Attach" },
	{ "IDS_PLEASE_ENTER_A_FILENAME", "Please enter a filename." },
	{ "IDS_OVERWRITE_EXISTING_IMAGE", "Overwrite existing image?" },
	{ "IDS_CANNOT_CREATE_IMAGE", "Cannot create image file!" },
	{ "IDS_COMMAND_LINE_OPTIONS", "Command line options" },
	{ "IDS_COMMAND_OPTIONS_AVAIL", "Which command line options are available?" },
	{ "IDS_NO_DRIVER_SELECT_SUPPORT", "No driver selected or selected driver not supported" },
	{ "IDS_CANT_WRITE_SCREENSHOT_S", "Cannot write screenshot file `%s'." },
	{ "IDS_AUTOSTART_DISK_IMAGE", "Autostart disk image" },
	{ "IDS_SELECT_FS_DIRECTORY", "Select file system directory" },
	{ "IDS_PRINTER_USERPORT", "Printer Userport" },
	{ "IDS_PRINTER_4", "Printer 4" },
	{ "IDS_PRINTER_5", "Printer 5" },
	{ "IDS_DRIVE_8", "Drive 8" },
	{ "IDS_DRIVE_9", "Drive 9" },
	{ "IDS_DRIVE_10", "Drive 10" },
	{ "IDS_DRIVE_11", "Drive 11" },
	{ "IDS_PERIPHERAL_SETTINGS", "Peripheral settings" },
	{ "IDS_CANT_WRITE_SNAPSHOT_FILE", "Can't write snapshot file." },
	{ "IDS_CANNOT_READ_SNAPSHOT_IMG", "Cannot read snapshot image" },
	{ "IDS_LOAD_S_ROM_IMAGE", "Load %s ROM image" },
	{ "IDS_SELECT_ROMSET_ARCHIVE", "Select romset archive" },
	{ "IDS_CANNOT_LOAD_ROMSET_ARCH", "Cannot load romset archive!" },
	{ "IDS_CANNOT_SAVE_ROMSET_ARCH", "Cannot save romset archive!" },
	{ "IDS_CANNOT_LOAD_ROMSET_FILE", "Cannot load romset file!" },
	{ "IDS_CANNOT_SAVE_ROMSET_FILE", "Cannot save romset file!" },
	{ "IDS_SELECT_ROMSET_FILE", "Select romset file" },
	{ "IDS_ROMSET", "Romset" },
	{ "IDS_COMPUTER", "Computer" },
	{ "IDS_DRIVE", "Drive" },
	{ "IDS_ROM_SETTINGS", "ROM settings" },
	{ "IDS_SAVE_SNAPSHOT_IMAGE", "Save snapshot image" },
	{ "IDS_CANNOT_WRITE_SNAPSHOT_S", "Cannot write snapshot file `%s'." },
	{ "IDS_LOAD_SNAPSHOT_IMAGE", "Load snapshot image" },
	{ "IDS_COULD_NOT_LOAD_PALETTE", "Could not load palette file." },
	{ "IDS_LOAD_VICE_PALETTE_FILE", "Load VICE palette file" },
	{ "IDS_FULLSCREEN", "Fullscreen/DirectX" },
	{ "IDS_CRT_EMULATION", "CRT emulation" },
	{ "IDS_RENDER_FILTER", "Render filter" },
	{ "IDS_SCALE2X", "Scale2x" },
	{ "IDS_VIDEO_SETTINGS", "Video settings" },
	{ "IDS_FILE_SYSTEM", "File system" },
	{ "IDS_REAL_IEC_DEVICE", "Real IEC device" },
	{ "IDS_RS232_DEVICE_I", "RS232 device %i" },
	{ "IDS_ATTACH_CRT_CART_IMAGE", "Attach CRT cartridge image" },
	{ "IDS_ATTACH_RAW_8KB_CART_IMAGE", "Attach raw 8KB cartridge image" },
	{ "IDS_ATTACH_RAW_16KB_CART_IMG", "Attach raw 16KB cartridge image" },
	{ "IDS_ATTACH_AR_CART_IMAGE", "Attach raw 32KB Action Replay cartridge image" },
	{ "IDS_ATTACH_AR3_CART_IMAGE", "Attach raw 16KB Action Replay MK3 cartridge image" },
	{ "IDS_ATTACH_AR4_CART_IMAGE", "Attach raw 32KB Action Replay MK4 cartridge image" },
	{ "IDS_ATTACH_STARDOS_CART_IMAGE", "Attach raw 16KB Stardos cartridge image" },
	{ "IDS_ATTACH_ATOMIC_P_CART_IMG", "Attach raw 32KB Atomic Power cartridge image" },
	{ "IDS_ATTACH_EPYX_FL_CART_IMG", "Attach raw 8KB Epyx FastLoad cartridge image" },
	{ "IDS_ATTACH_IEEE488_CART_IMG", "Attach IEEE-488 Interface cartridge image" },
	{ "IDS_ATTACH_RETRO_R_CART_IMG", "Attach raw 64KB Retro Replay cartridge image" },
	{ "IDS_ATTACH_MMC_REPLAY_CART_IMG", "Attach raw 512kB MMC Replay cartridge image" },
	{ "IDS_ATTACH_IDE64_CART_IMAGE", "Attach raw 64KB IDE64 cartridge image" },
	{ "IDS_ATTACH_SS4_CART_IMAGE", "Attach raw 32KB Super Snapshot V4 cartridge image" },
	{ "IDS_ATTACH_SS5_CART_IMAGE", "Attach raw 64KB Super Snapshot V5 cartridge image" },
	{ "IDS_ATTACH_STB_CART_IMAGE", "Attach raw Structured Basic cartridge image" },
	{ "IDS_SELECT_CARTRIDGE_IMAGE", "Select cartridge file" },
	{ "IDS_MODEL", "Model" },
	{ "IDS_DRIVE_SETTINGS", "Drive settings" },
	{ "IDS_SELECT_START_SNAP_EVENT", "Select start snapshot for event history" },
	{ "IDS_SELECT_END_SNAP_EVENT", "Select end snapshot for event history" },
	{ "IDS_VERSION_S_UNSTABLE", "Version %s *UNSTABLE* (%s)" },
	{ "IDS_VERSION_S", "Version %s (%s)" },
	{ "IDS_VICE_CONTRIBUTORS", "VICE contributors" },
	{ "IDS_WHO_MADE_WHAT", "Who made what?" },
	{ "IDS_LICENSE", "License" },
	{ "IDS_NO_WARRANTY", "No warranty!" },
	{ "IDS_VICE_WITHOUT_WARRANTY", "VICE is distributed WITHOUT ANY WARRANTY!" },
	{ "IDS_PRESS_KEY_NORTHWEST", "Press key for NorthWest" },
	{ "IDS_PRESS_KEY_NORTH", "Press key for North" },
	{ "IDS_PRESS_KEY_NORTHEAST", "Press key for NorthEast" },
	{ "IDS_PRESS_KEY_EAST", "Press key for East" },
	{ "IDS_PRESS_KEY_SOUTHEAST", "Press key for SouthEast" },
	{ "IDS_PRESS_KEY_SOUTH", "Press key for South" },
	{ "IDS_PRESS_KEY_SOUTHWEST", "Press key for SouthWest" },
	{ "IDS_PRESS_KEY_WEST", "Press key for West" },
	{ "IDS_PRESS_KEY_FIRE", "Press key for Fire" },
	{ "IDS_NO_USERPORT_ADAPTER", "No userport joy adapter" },
	{ "IDS_CGA_USERPORT_ADAPTER", "CGA userport joy adapter" },
	{ "IDS_PET_USERPORT_ADAPTER", "PET userport joy adapter" },
	{ "IDS_HUMMER_USERPORT_ADAPTER", "Hummer userport joy adapter" },
	{ "IDS_OEM_USERPORT_ADAPTER", "OEM userport joy adapter" },
	{ "IDS_HIT_USERPORT_ADAPTER", "HIT userport joy adapter" },
	{ "IDS_KINGSOFT_USERPORT_ADAPTER", "Kingsoft userport joy adapter" },
	{ "IDS_STARBYTE_USERPORT_ADAPTER", "Starbyte userport joy adapter" },
	{ "IDS_NO_SIDCART_JOY", "Disable SID cartridge joystick" },
	{ "IDS_SIDCART_JOY", "Enable SID cartridge joystick" },
	{ "IDS_NUMPAD_AND_RCTRL", "Numpad + RCtrl" },
	{ "IDS_KEYSET_A", "Keyset A" },
	{ "IDS_KEYSET_B", "Keyset B" },
	{ "IDS_ALL_BUTTONS_AS_FIRE", "All buttons used as fire" },
	{ "IDS_NUMERIC_SEE_ABOVE", "numeric (see above)" },
	{ "IDS_NO_BUTTON_NO_AUTOFIRE", "No button - Autofire disabled" },
	{ "IDS_ALL_FILES_FILTER", "All files (*.*)" },
	{ "IDS_PALETTE_FILES_FILTER", "VICE palette files (*.vpl)" },
	{ "IDS_SNAPSHOT_FILES_FILTER", "VICE snapshot files (*.vsf)" },
	{ "IDS_CBM_IMAGE_FILES_FILTER", "CBM files (*.d64;*.d71;*.d80;*.d81;*.d82;*.d1m;*.d2m;*.d4m;*.g64;*.g41;*.p64;*.x64;*.t64;*.tap;*.prg;*.p00)" },
	{ "IDS_IDE64_IMAGE_FILES_FILTER", "IDE64 files (*.fdd;*.hdd;*.iso;*.cfa)" },
	{ "IDS_DISK_IMAGE_FILES_FILTER", "Disk image files (*.d64;*.d71;*.d80;*.d81;*.d82;*.d1m;*.d2m*;*.d4m;.g64;*.g41;*.p64;*.x64)" },
	{ "IDS_TAPE_IMAGE_FILES_FILTER", "Tape image files (*.t64;*.tap)" },
	{ "IDS_ZIPPED_FILES_FILTER", "Zipped files (*.zip;*.bz2;*.gz;*.d6z;*.d7z;*.d8z;*.g6z;*.g4z;*.p6z;*.x6z)" },
	{ "IDS_CRT_FILES_FILTER", "CRT cartridge image files (*.crt)" },
	{ "IDS_RAW_CART_FILES_FILTER", "Raw cartridge image files (*.bin)" },
	{ "IDS_FLIP_LIST_FILES_FILTER", "VICE flip list files (*.vfl)" },
	{ "IDS_ROMSET_FILES_FILTER", "VICE romset files (*.vrs)" },
	{ "IDS_ROMSET_ARCHIVES_FILTER", "VICE romset archives (*.vra)" },
	{ "IDS_KEYMAP_FILES_FILTER", "VICE keymap files (*.vkm)" },
	{ "IDS_PRGP00_FILES_FILTER", "Commodore emulator files (*.prg;*.p00)" },
	{ "IDS_FLEXIBLE", "Flexible" },
	{ "IDS_ADJUSTING", "Adjusting" },
	{ "IDS_EXACT", "Exact" },
	{ "IDS_SOUND_DRIVER_DIRECTX", "Sound driver: DirectX" },
	{ "IDS_SOUND_DRIVER_WMM", "Sound driver: WMM" },
	{ "IDS_SYSTEM", "System" },
	{ "IDS_MONO", "Mono" },
	{ "IDS_STEREO", "Stereo" },
	{ "IDS_MEDIA_FILES_FILTER", "Media files (*.bmp;*.gif;*.iff;*.jpg;*.pcx;*.png;*.ppm;*.wav;*.mp3;*.avi;*.mpg)" },
	{ "IDS_SPACE_KB", " kB" },
	{ "IDS_CONFIGURE_KEYSET_A", "Configure Keyset A" },
	{ "IDS_CONFIGURE_KEYSET_B", "Configure Keyset B" },
	{ "IDS_SAVE_MEDIA_IMAGE", "Save media file" },
	{ "IDS_S_AT_D_SPEED", "%s at %d%% speed, %d fps%s" },
	{ "IDS_TAPE", "Tape:" },
	{ "IDS_JOYSTICK_C", "Joystick:" },
	{ "IDS_RECORDING", "Recording\n%02d:%02d" },
	{ "IDS_PLAYBACK", "Playback\n%02d:%02d (%02d:%02d)" },
	{ "IDS_UNKNOWN", "Unknown" },
	{ "IDS_P_NUMBER", "<number>" },
	{ "IDS_SET_INPUT_JOYSTICK_1", "Set input device for joystick #1" },
	{ "IDS_SET_INPUT_JOYSTICK_2", "Set input device for joystick #2" },
	{ "IDS_SET_INPUT_EXTRA_JOYSTICK_1", "Set input device for extra joystick #1" },
	{ "IDS_SET_INPUT_EXTRA_JOYSTICK_2", "Set input device for extra joystick #2" },
	{ "IDS_SAVE_SETTINGS_ON_EXIT", "Save settings on exit" },
	{ "IDS_NO_SAVE_SETTINGS_ON_EXIT", "Never save settings on exit" },
	{ "IDS_CONFIRM_QUIT_VICE", "Confirm quitting VICE" },
	{ "IDS_NO_CONFIRM_QUIT_VICE", "Never confirm quitting VICE" },
	{ "IDS_USE_ALL_CPU_SMP", "Use all CPU on SMP systems" },
	{ "IDS_USE_FIRST_CPU_SMP", "Use only first CPU on SMP systems" },
	{ "IDS_START_VICE_FULLSCREEN_MODE", "Start VICE in fullscreen mode" },
	{ "IDS_DISABLE_DX9", "Disable DirectX9 video driver" },
	{ "IDS_RECEIVED_SIGNAL_D_S", "An unexpected error occured. Received signal %d (%s)." },
	{ "IDS_RECEIVED_SIGNAL_D", "An unexpected error occured. Received signal %d." },
	{ "IDS_IDLE", "Idle" },
	{ "IDS_SERVER_LISTENING", "Server listening" },
	{ "IDS_CONNECTED_SERVER", "Connected server" },
	{ "IDS_CONNECTED_CLIENT", "Connected client" },
	{ "IDS_INVALID_PORT_NUMBER", "Invalid port number" },
	{ "IDS_ERROR_STARTING_SERVER", "An error occured starting the server." },
	{ "IDS_ERROR_CONNECTING_CLIENT", "An error occured connecting the client." },
	{ "IDS_SOUND_RECORDING_STARTED", "Sound Recording started..." },
	{ "IDS_SOUND_RECORDING_STOPPED", "Sound Recording stopped..." },
	{ "IDS_OK", "OK" },
	{ "IDS_CANCEL", "Cancel" },
	{ "IDS_NONE", "None" },
	{ "IDS_BROWSE", "Browse..." },
	{ "IDS_SPECIFY_MIDI_IN", "Specify MIDI-In device" },
	{ "IDS_SPECIFY_MIDI_OUT", "Specify MIDI-Out device" },
	{ "IDS_ERROR_SAVING_EASYFLASH_CRT", "Error saving EasyFlash crt file" },
	{ "IDS_NO_EASYFLASH_CART_INSERTED", "No EasyFlash cartridge inserted" },
	{ "IDS_DATASETTE_CAPTION", "Datasette settings" },
	{ "IDS_DATASETTE_RESET_WITH_CPU", "Reset Datasette with CPU" },
	{ "IDS_DATASETTE_MOTOR_GROUP", "Speed of motor while reading" },
	{ "IDS_DATASETTE_DELAY_TRIGGER", "cycle(s) additional delay each trigger" },
	{ "IDS_DATASETTE_DELAY_AT_ZERO", "Datasette zero gap delay" },
	{ "IDS_TOGGLE_USEIECDEVICE", "Use IEC Device" },
	{ "IDS_SELECTDISK", "Disk image" },
	{ "IDS_SELECTDIR", "Directory" },
	{ "IDS_SELECTREAL", "Real IEC device" },
	{ "IDS_SELECTNONE", "None" },
	{ "IDS_AUTOSTART", "Autostart" },
	{ "IDS_BROWSEDIR", "Browse..." },
	{ "IDS_TOGGLE_ATTACH_READONLY", "Attach read only" },
	{ "IDS_TOGGLE_READP00", "Read P00 files" },
	{ "IDS_TOGGLE_WRITEP00", "Write P00 files" },
	{ "IDS_TOGGLE_HIDENONP00", "Hide non-P00 files" },
	{ "IDS_JOYSTICK_CAPTION", "Joystick settings" },
	{ "IDS_JOYSTICK_IN_PORT_1", "Joystick in port #1" },
	{ "IDS_SELECT_FIRE_BUTTON", "Select fire button" },
	{ "IDS_AUTO_FIRE_BUTTON_SETTINGS", "Auto fire button settings" },
	{ "IDS_AUTOFIRE_SPEED", "Autofire speed (1..32)" },
	{ "IDS_JOYSTICK_IN_PORT_2", "Joystick in port #2" },
	{ "IDS_JOY_CONFIG_A", "Configure Keyset A" },
	{ "IDS_JOY_CONFIG_B", "Configure Keyset B" },
	{ "IDS_JOY_CALIBRATE", "Calibrate Joystick(s)" },
	{ "IDS_EXTRA_JOYSTICK_CAPTION", "Extra joystick settings" },
	{ "IDS_JOYSTICK_IN_EXTRA_PORT_1", "Joystick in extra port #1" },
	{ "IDS_JOYSTICK_IN_EXTRA_PORT_2", "Joystick in extra port #2" },
	{ "IDS_KEYSET_SW", "South West" },
	{ "IDS_KEYSET_S", "South" },
	{ "IDS_KEYSET_SE", "South East" },
	{ "IDS_KEYSET_W", "West" },
	{ "IDS_KEYSET_E", "East" },
	{ "IDS_KEYSET_NW", "North West" },
	{ "IDS_KEYSET_N", "North" },
	{ "IDS_KEYSET_NE", "North East" },
	{ "IDS_KEYSET_FIRE", "Fire button" },
	{ "IDS_SOUND_CAPTION", "Configure Sound Device Settings" },
	{ "IDS_SOUND_DIRECTX", "DirectX driver" },
	{ "IDS_SOUND_WMM", "WMM driver" },
	{ "IDS_SOUND_OUTPUT_MODE", "Sound output mode" },
	{ "IDS_SOUND_SAMPLE_FREQUENCY", "Sample rate :" },
	{ "IDS_SOUND_BUFFER_SIZE", "Sound Buffer Size :" },
	{ "IDS_SOUND_FRAGMENT_SIZE_LABEL", "Sound Fragment Size :" },
	{ "IDS_SOUND_FRAGMENT_SIZE_SMALL", "Small" },
	{ "IDS_SOUND_FRAGMENT_SIZE_MEDIUM", "Medium" },
	{ "IDS_SOUND_FRAGMENT_SIZE_LARGE", "Large" },
	{ "IDS_SOUND_SYNCH_METHOD", "Synchronization Method :" },
	{ "IDS_TOGGLE_SNAPSHOT_SAVE_DISKS", "Save currently attached disk images" },
	{ "IDS_TOGGLE_SNAPSHOT_SAVE_ROMS", "Save currently loaded ROM images" },
	{ "IDS_FULLSCREEN_DRIVER", "Driver:" },
	{ "IDS_FULLSCREEN_DRVR_BITDEPTH", "Bitdepth:" },
	{ "IDS_FULLSCREEN_DRVR_RESOLUTION", "Resolution:" },
	{ "IDS_FULLSCREEN_DRVR_REFRESHRATE", "Refresh rate:" },
	{ "IDS_TOGGLE_VIDEO_VBLANK_SYNC", "VBLANK synchronization" },
	{ "IDS_TOGGLE_VIDEO_DX_PRIMARY", "Render to DX Primary surface" },
	{ "IDS_TOGGLE_KEEP_ASPECT_RATIO", "Keep aspect ratio (0,5..2)" },
	{ "IDS_TOGGLE_TRUE_ASPECT_RATIO", "True aspect ratio" },
	{ "IDS_VAL_F_FOR_S_OUT_RANGE_USE_F", "Value %.3f for %s is out of range, using %.3f instead" },
	{ "IDS_VAL_D_FOR_S_OUT_RANGE_USE_D", "Value %d for %s is out of range, using %d instead" },
	{ "IDS_AUDIO_LEAK", "Audio leak" },
	{ "IDS_COLORS_GAMMA", "Gamma (0..4)" },
	{ "IDS_COLORS_TINT", "Tint (0..2)" },
	{ "IDS_COLORS_SATURATION", "Saturation (0..2)" },
	{ "IDS_COLORS_CONTRAST", "Contrast (0..2)" },
	{ "IDS_COLORS_BRIGHTNESS", "Brightness (0..2)" },
	{ "IDS_CRT_SCANLINE_SHADE", "Scanline shade (0..1)" },
	{ "IDS_CRT_BLUR", "Blur (0..1)" },
	{ "IDS_CRT_ODDLINE_PHASE", "Odd lines phase (0..2)" },
	{ "IDS_CRT_ODDLINE_OFFSET", "Odd lines offset (0..2)" },
	{ "IDS_VICII_PALETTE", "VICII Palette" },
	{ "IDS_VIC_PALETTE", "VIC Palette" },
	{ "IDS_CRTC_PALETTE", "CRTC Palette" },
	{ "IDS_VDC_PALETTE", "VDC Palette" },
	{ "IDS_TED_PALETTE", "TED Palette" },
	{ "IDS_VICII_COLORS", "VICII Colors" },
	{ "IDS_VIC_COLORS", "VIC Colors" },
	{ "IDS_CRTC_COLORS", "CRTC Colors" },
	{ "IDS_VDC_COLORS", "VDC Colors" },
	{ "IDS_TED_COLORS", "TED Colors" },
	{ "IDS_VICII_CRT_EMULATION", "VICII CRT emulation" },
	{ "IDS_VIC_CRT_EMULATION", "VIC CRT emulation" },
	{ "IDS_CRTC_CRT_EMULATION", "CRTC CRT emulation" },
	{ "IDS_VDC_CRT_EMULATION", "VDC CRT emulation" },
	{ "IDS_TED_CRT_EMULATION", "TED CRT emulation" },
	{ "IDS_VICII_RENDER_FILTER", "VICII Render filter" },
	{ "IDS_VIC_RENDER_FILTER", "VIC Render filter" },
	{ "IDS_CRTC_RENDER_FILTER", "CRTC Render filter" },
	{ "IDS_VDC_RENDER_FILTER", "VDC Render filter" },
	{ "IDS_TED_RENDER_FILTER", "TED Render filter" },
	{ "IDS_VICII_AUDIO_LEAK", "VICII Audio leak" },
	{ "IDS_VIC_AUDIO_LEAK", "VIC Audio leak" },
	{ "IDS_CRTC_AUDIO_LEAK", "CRTC Audio leak" },
	{ "IDS_VDC_AUDIO_LEAK", "VDC Audio leak" },
	{ "IDS_TED_AUDIO_LEAK", "TED Audio leak" },
	{ "IDS_TOGGLE_VIDEO_EXTPALETTE", "External Palette:" },
	{ "IDS_RAM_CAPTION", "RAM settings" },
	{ "IDS_RAM_INIT_AT_POWERUP", "Initialization at powerup" },
	{ "IDS_RAM_VALUE_FIRST_BYTE", "Value of first byte" },
	{ "IDS_RAM_LENGTH_CONSTANT_VALUES", "Length of constant values" },
	{ "IDS_RAM_LENGTH_CONSTANT_PATTERN", "Length of constant pattern" },
	{ "IDS_PRINTER_EMULATION", "Printer emulation" },
	{ "IDS_PRINTER_FORMFEED", "Send Formfeed" },
	{ "IDS_FILESYSTEM_PRINTER", "File system printer" },
	{ "IDS_PRINTER_DRVR", "Printer driver" },
	{ "IDS_OUTPUT", "Output" },
	{ "IDS_OUTPUT_TO_FILE", "Output to file #" },
	{ "IDS_OUTPUT_FILE1_NAME", "Output file #1 name" },
	{ "IDS_OUTPUT_FILE2_NAME", "Output file #2 name" },
	{ "IDS_OUTPUT_FILE3_NAME", "Output file #3 name" },
	{ "IDS_ROMSET_SELECT_ARCHIVE", "Romset archive" },
	{ "IDS_ROMSET_ARCHIVE_LOAD", "Load archive" },
	{ "IDS_ROMSET_ARCHIVE_SAVE", "Save archive" },
	{ "IDS_ROMSET_CONFIGURATION", "Configuration" },
	{ "IDS_ROMSET_ARCHIVE_APPLY", "Apply" },
	{ "IDS_ROMSET_ARCHIVE_NEW", "New" },
	{ "IDS_ROMSET_ARCHIVE_DELETE", "Delete" },
	{ "IDS_ROMSET_SELECT_FILE", "Romset file" },
	{ "IDS_ROMSET_FILE_LOAD", "Load romset" },
	{ "IDS_ROMSET_FILE_SAVE", "Save romset" },
	{ "IDS_CUSTOM_SPEED_CAPTION", "Custom speed" },
	{ "IDS_ENTER_CUSTOM_SPEED", "Enter custom speed [%]" },
	{ "IDS_NEW_CONFIGURATION", "New configuration" },
	{ "IDS_ENTER_CONFIGURATION_NAME", "Enter configuration name" },
	{ "IDS_RS232_CAPTION", "RS232 settings" },
	{ "IDS_RS232_DEV_1", "RS232 device 1" },
	{ "IDS_RS232_DEV_2", "RS232 device 2" },
	{ "IDS_RS232_DEV_3", "RS232 device 3" },
	{ "IDS_RS232_DEV_4", "RS232 device 4" },
	{ "IDS_NETWORK_CAPTION", "Netplay Settings" },
	{ "IDS_CURRENT_MODE", "Current mode" },
	{ "IDS_SERVER_BIND", "Server Bind" },
	{ "IDS_TCP_PORT", "TCP port" },
	{ "IDS_NETWORK_SERVER", "Start server" },
	{ "IDS_NETWORK_CLIENT", "Connect to" },
	{ "IDS_NETWORK_DISCONNECT", "Disconnect" },
	{ "IDS_CONTROL", "Control" },
	{ "IDS_SERVER", "Server" },
	{ "IDS_CLIENT", "Client" },
	{ "IDS_KEYBOARD", "Keyboard" },
	{ "IDS_JOYSTICK_1", "Joystick 1" },
	{ "IDS_JOYSTICK_2", "Joystick 2" },
	{ "IDS_DEVICES", "Devices" },
	{ "IDS_SETTINGS", "Settings" },
	{ "IDS_TOGGLE_CONSOLE_APPEND", "Append log to existing file" },
	{ "IDS_IMAGE_CONTENTS", "Image Contents" },
	{ "IDS_NEW_IMAGE", "New Image" },
	{ "IDS_NAME", "Name" },
	{ "IDS_ID", "ID" },
	{ "IDS_TYPE", "Type" },
	{ "IDS_BLANK_IMAGE", "Create Image" },
	{ "IDS_NEW_TAP_IMAGE", "New TAP Image" },
	{ "IDS_SAVE", "Save" },
	{ "IDS_SELECT_DRIVER", "Select Driver" },
	{ "IDS_FFMPEG_SETTINGS", "FFMPEG settings" },
	{ "IDS_FORMAT", "Format" },
	{ "IDS_AUDIO_CODEC", "Audio codec" },
	{ "IDS_BITRATE", "bitrate" },
	{ "IDS_VIDEO_CODEC", "Video codec" },
	{ "IDS_SOUND_RECORD_CAPTION", "Sound record settings" },
	{ "IDS_SOUND_RECORD_FORMAT_LABEL", "Sound Record Format" },
	{ "IDS_SOUND_RECORD_FILE_LABEL", "Sound Record File" },
	{ "IDS_KERNAL", "Kernal" },
	{ "IDS_BASIC", "Basic" },
	{ "IDS_CHARACTER", "Character" },
	{ "IDS_COMPUTER_RESOURCES_CAPTION", "Computer resources" },
	{ "IDS_COMPUTER_RESOURCES", "Computer resources saved to romset" },
	{ "IDS_DRIVE_RESOURCES_CAPTION", "Drive resources" },
	{ "IDS_DRIVE_RESOURCES", "Drive resources saved to romset" },
	{ "IDS_SYMBOLIC", "Symbolic" },
	{ "IDS_POSITIONAL", "Positional" },
	{ "IDS_DUMP_KEYSET", "Dump keyset" },
	{ "IDS_DUMP_SHORTCUTS", "Dump shortcuts" },
	{ "IDS_SYMBOLIC_US", "Symbolic US" },
	{ "IDS_SYMBOLIC_DE", "Symbolic DE" },
	{ "IDS_GR_SYM", "Gr Sym." },
	{ "IDS_GR_POS", "Gr Pos." },
	{ "IDS_UK_SYM", "UK Sym." },
	{ "IDS_UK_POS", "UK Pos." },
	{ "IDS_DE_SYM", "DE Sym." },
	{ "IDS_DE_POS", "DE Pos." },
	{ "IDS_MEMORY", "Memory" },
	{ "IDS_DRIVE_TYPE", "Drive type" },
	{ "IDS_40_TRACK_HANDLING", "40 track handling" },
	{ "IDS_SELECT_DRIVE_EXTEND_NEVER", "Never extend" },
	{ "IDS_SELECT_DRIVE_EXTEND_ASK", "Ask on extend" },
	{ "IDS_SELECT_DRIVE_EXTEND_ACCESS", "Extend on access" },
	{ "IDS_IDLE_METHOD", "Idle method" },
	{ "IDS_SELECT_DRIVE_IDLE_TRAP_IDLE", "Trap idle" },
	{ "IDS_SELECT_DRIVE_IDLE_SKIP_CYC", "Skip cycles" },
	{ "IDS_TOGGLE_DRIVE_PARALLEL_CABLE", "Parallel cable" },
	{ "IDS_STANDARD", "Standard" },
	{ "IDS_DRIVE_EXPANSION", "Drive expansion" },
	{ "IDS_TOGGLE_DRIVE_EXPANSION_2000", "$2000-$3FFF RAM" },
	{ "IDS_TOGGLE_DRIVE_EXPANSION_4000", "$4000-$5FFF RAM" },
	{ "IDS_TOGGLE_DRIVE_EXPANSION_6000", "$6000-$7FFF RAM" },
	{ "IDS_TOGGLE_DRIVE_EXPANSION_8000", "$8000-$9FFF RAM" },
	{ "IDS_TOGGLE_DRIVE_EXPANSION_A000", "$A000-$BFFF RAM" },
	{ "IDS_PLUS4_VIC20_MEMORY", "Memory" },
	{ "IDS_SID_GENGROUP1", "SID model" },
	{ "IDS_SID_FILTERS", "SID filters" },
	{ "IDS_MP_FILE", "File" },
	{ "IDS_MP_ATTACH_DISK_IMAGE", "Attach disk image" },
	{ "IDS_MP_DETACH_DISK_IMAGE", "Detach disk image" },
	{ "IDS_MP_FLIP_LIST", "Flip list" },
	{ "IDS_MP_DATASETTE_CONTROL", "Datassette control" },
	{ "IDS_MP_ATTACH_CARTRIDGE_IMAGE", "Attach cartridge image..." },
	{ "IDS_MP_RESET", "Reset" },
	{ "IDS_MP_DEBUG", "Debug" },
	{ "IDS_MP_MODE", "Mode" },
	{ "IDS_MP_EDIT", "Edit" },
	{ "IDS_MP_SNAPSHOT", "Snapshot" },
	{ "IDS_MP_RECORDING_START_MODE", "Recording start mode" },
	{ "IDS_MP_OPTIONS", "Options" },
	{ "IDS_MP_REFRESH_RATE", "Refresh rate" },
	{ "IDS_MP_MAXIMUM_SPEED", "Maximum speed" },
	{ "IDS_MP_VIDEO_STANDARD", "Video standard" },
	{ "IDS_MP_DRIVE_SYNC_FACTOR", "Drive sync factor" },
	{ "IDS_MP_SETTINGS", "Settings" },
	{ "IDS_MP_CARTRIDGE_IO_SETTINGS", "Cartridge/IO settings" },
	{ "IDS_MP_LANGUAGE", "Language" },
	{ "IDS_MP_HELP", "Help" },
	{ "IDS_MP_VIEW", "View" },
	{ "IDS_MP_WINDOW", "Window" },
	{ "IDS_MI_EXIT", "Exit" },
	{ "IDS_MI_ABOUT", "About VICE..." },
	{ "IDS_MI_PAUSE", "Pause" },
	{ "IDS_MI_EDIT_COPY", "Copy" },
	{ "IDS_MI_EDIT_PASTE", "Paste" },
	{ "IDS_MI_AUTOSTART", "Autostart disk/tape image..." },
	{ "IDS_MI_RESET_HARD", "Hard" },
	{ "IDS_MI_RESET_SOFT", "Soft" },
	{ "IDS_MI_DRIVE8", "Drive 8" },
	{ "IDS_MI_DRIVE9", "Drive 9" },
	{ "IDS_MI_DRIVE10", "Drive 10" },
	{ "IDS_MI_DRIVE11", "Drive 11" },
	{ "IDS_MI_ATTACH_TAPE", "Attach tape image..." },
	{ "IDS_MI_DETACH_TAPE", "Detach tape image" },
	{ "IDS_MI_DETACH_ALL", "All" },
	{ "IDS_MI_TOGGLE_SOUND", "Sound playback" },
	{ "IDS_MI_TOGGLE_DOUBLESIZE", "Double size" },
	{ "IDS_MI_TOGGLE_DOUBLESCAN", "Double scan" },
	{ "IDS_MI_TOGGLE_DOUBLEVERTICAL", "Double vertical" },
	{ "IDS_MI_DRIVE_TRUE_EMULATION", "True drive emulation" },
	{ "IDS_MI_DRIVE_SOUND_EMULATION", "Drive sound emulation" },
	{ "IDS_MI_AUTOSTART_HANDLE_TDE", "Handle True Drive Emulation on autostart" },
	{ "IDS_MI_TOGGLE_VIDEOCACHE", "Video cache" },
	{ "IDS_MI_DRIVE_SETTINGS", "Drive settings..." },
	{ "IDS_MI_CART_SMART_ATTACH", "Smart-attach image..." },
	{ "IDS_MI_CART_ATTACH_CRT", "CRT image..." },
	{ "IDS_MI_CART_ATTACH_8KB", "Generic 8KB image..." },
	{ "IDS_MI_CART_ATTACH_16KB", "Generic 16KB image..." },
	{ "IDS_MI_CART_ATTACH_AR", "Action Replay image..." },
	{ "IDS_MI_CART_ATTACH_AR3", "Action Replay MK3 image..." },
	{ "IDS_MI_CART_ATTACH_AR4", "Action Replay MK4 image..." },
	{ "IDS_MI_CART_ATTACH_STARDOS", "Stardos image..." },
	{ "IDS_MI_CART_ATTACH_AT", "Atomic Power image..." },
	{ "IDS_MI_CART_ATTACH_EPYX", "Epyx FastLoad image..." },
	{ "IDS_MI_CART_ATTACH_IEEE488", "IEEE-488 Interface image..." },
	{ "IDS_MI_CART_ATTACH_RR", "Retro Replay image..." },
	{ "IDS_MI_CART_ATTACH_MMC_REPLAY", "MMC Replay image..." },
	{ "IDS_MI_CART_ATTACH_IDE64", "IDE64 interface image..." },
	{ "IDS_MI_CART_ATTACH_SS4", "Super Snapshot V4 image..." },
	{ "IDS_MI_CART_ATTACH_SS5", "Super Snapshot V5 image..." },
	{ "IDS_MI_CART_ATTACH_STB", "Structured BASIC image..." },
	{ "IDS_MI_FLIP_ADD", "Add current image (Unit 8)" },
	{ "IDS_MI_FLIP_REMOVE", "Remove current image (Unit 8)" },
	{ "IDS_MI_FLIP_NEXT", "Attach next image (Unit 8)" },
	{ "IDS_MI_FLIP_PREVIOUS", "Attach previous image (Unit 8)" },
	{ "IDS_MI_FLIP_LOAD", "Load flip list file" },
	{ "IDS_MI_FLIP_SAVE", "Save flip list file" },
	{ "IDS_MI_DATASETTE_STOP", "Stop" },
	{ "IDS_MI_DATASETTE_START", "Start" },
	{ "IDS_MI_DATASETTE_FORWARD", "Forward" },
	{ "IDS_MI_DATASETTE_REWIND", "Rewind" },
	{ "IDS_MI_DATASETTE_RECORD", "Record" },
	{ "IDS_MI_DATASETTE_RESET", "Reset" },
	{ "IDS_MI_DATASETTE_RESET_COUNTER", "Reset Counter" },
	{ "IDS_MI_CART_SET_DEFAULT", "Set cartridge as default" },
	{ "IDS_MI_TOGGLE_CART_RESET", "Reset on cart change" },
	{ "IDS_MI_CART_DETACH", "Detach cartridge image(s)" },
	{ "IDS_MI_CART_FREEZE", "Cartridge freeze" },
	{ "IDS_MI_MONITOR", "Monitor" },
	{ "IDS_MI_DEBUG_MODE_NORMAL", "Normal" },
	{ "IDS_MI_DEBUG_MODE_SMALL", "Small" },
	{ "IDS_MI_DEBUG_MODE_HISTORY", "History" },
	{ "IDS_MI_DEBUG_MODE_AUTOPLAY", "History Autoplay" },
	{ "IDS_MI_TOGGLE_MAINCPU_TRACE", "Main CPU Trace" },
	{ "IDS_MI_TOGGLE_DRIVE0CPU_TRACE", "Drive0 CPU Trace" },
	{ "IDS_MI_TOGGLE_DRIVE1CPU_TRACE", "Drive1 CPU Trace" },
	{ "IDS_MI_SNAPSHOT_LOAD", "Load snapshot image..." },
	{ "IDS_MI_SNAPSHOT_SAVE", "Save snapshot image..." },
	{ "IDS_MI_LOADQUICK", "Load quicksnapshot image" },
	{ "IDS_MI_SAVEQUICK", "Save quicksnapshot image" },
	{ "IDS_MI_EVENT_TOGGLE_RECORD", "Start/Stop Recording History" },
	{ "IDS_MI_EVENT_TOGGLE_PLAYBACK", "Start/Stop Playback History" },
	{ "IDS_MI_EVENT_SETMILESTONE", "Set recording milestone" },
	{ "IDS_MI_EVENT_RESETMILESTONE", "Return to milestone" },
	{ "IDS_MI_EVENT_START_MODE_SAVE", "Save new snapshot" },
	{ "IDS_MI_EVENT_START_MODE_LOAD", "Load existing snapshot" },
	{ "IDS_MI_EVENT_START_MODE_RESET", "Start with reset" },
	{ "IDS_MI_EVENT_START_MODE_PLAYBCK", "Overwrite Playback" },
	{ "IDS_MI_EVENT_DIRECTORY", "Select History files/directory" },
	{ "IDS_MI_MEDIAFILE", "Save/stop media file..." },
	{ "IDS_MI_SOUND_RECORD_START", "Record sound to file..." },
	{ "IDS_MI_SOUND_RECORD_STOP", "Stop Sound record" },
	{ "IDS_MI_REFRESH_RATE_AUTO", "Auto" },
	{ "IDS_MI_MAXIMUM_SPEED_NO_LIMIT", "No limit" },
	{ "IDS_MI_MAXIMUM_SPEED_CUSTOM", "Custom" },
	{ "IDS_MI_TOGGLE_WARP_MODE", "Warp mode" },
	{ "IDS_MI_TOGGLE_ALWAYSONTOP", "Always on Top" },
	{ "IDS_MI_TOGGLE_DX9DISABLE", "Disable DirectX9 video driver" },
	{ "IDS_MI_SWAP_JOYSTICK", "Swap joysticks" },
	{ "IDS_MI_SWAP_EXTRA_JOYSTICK", "Swap userport joysticks" },
	{ "IDS_MI_ALLOW_JOY_OPPOSITE", "Allow opposite directions" },
	{ "IDS_MI_JOYKEYS_TOGGLE", "Enable Joy Keys" },
	{ "IDS_MI_TOGGLE_VIRTUAL_DEVICES", "Virtual device traps" },
	{ "IDS_MI_MOUSE", "Grab mouse events" },
	{ "IDS_MI_C64MODEL_SETTINGS", "C64 model settings..." },
	{ "IDS_MI_AUTOSTART_SETTINGS", "Autostart settings..." },
	{ "IDS_MI_VIDEO_SETTINGS", "Video settings..." },
	{ "IDS_MI_DEVICEMANAGER", "Peripheral settings..." },
	{ "IDS_MI_JOY_SETTINGS", "Joystick settings..." },
	{ "IDS_MI_USERPORT_JOY_SETTINGS", "Userport joystick settings..." },
	{ "IDS_MI_SIDCART_JOY_SETTINGS", "Sidcart joystick settings..." },
	{ "IDS_MI_KEYBOARD_SETTINGS", "Keyboard settings..." },
	{ "IDS_MI_SOUND_SETTINGS", "Sound settings..." },
	{ "IDS_MI_ROM_SETTINGS", "ROM settings..." },
	{ "IDS_MI_RAM_SETTINGS", "RAM settings..." },
	{ "IDS_MI_DATASETTE_SETTINGS", "Datasette settings..." },
	{ "IDS_MI_VICII_SETTINGS", "VIC-II settings..." },
	{ "IDS_MI_MOUSE_SETTINGS", "Mouse settings..." },
	{ "IDS_MI_SID_SETTINGS", "SID settings..." },
	{ "IDS_MI_RS232_SETTINGS", "RS232 settings..." },
	{ "IDS_MI_REU_SETTINGS", "REU settings..." },
	{ "IDS_MI_GEORAM_SETTINGS", "GEO-RAM settings..." },
	{ "IDS_MI_RAMCART_SETTINGS", "RamCart settings..." },
	{ "IDS_MI_DQBB_SETTINGS", "Double Quick Brown Box settings..." },
	{ "IDS_MI_EXPERT_SETTINGS", "Expert Cartridge settings..." },
	{ "IDS_MI_ISEPIC_SETTINGS", "ISEPIC settings..." },
	{ "IDS_MI_MMC64_SETTINGS", "MMC64 settings..." },
	{ "IDS_MI_MMCREPLAY_SETTINGS", "MMC Replay settings..." },
	{ "IDS_MI_RR_SETTINGS", "Retro Replay settings..." },
	{ "IDS_MI_MAGICVOICE_SETTINGS", "Magic Voice settings..." },
	{ "IDS_MI_MIDI_SETTINGS", "MIDI settings..." },
	{ "IDS_MI_DIGIMAX_SETTINGS", "DigiMAX settings..." },
	{ "IDS_MI_DS12C887RTC_SETTINGS", "DS12C887 RTC settings..." },
	{ "IDS_MI_LIGHTPEN_SETTINGS", "Lightpen settings..." },
	{ "IDS_MI_IDE64_SETTINGS", "IDE64 settings..." },
	{ "IDS_MI_TFE_SETTINGS", "Ethernet settings..." },
	{ "IDS_MI_ACIA_SETTINGS", "ACIA settings..." },
	{ "IDS_MI_RS232USER_SETTINGS", "RS232 userport settings..." },
	{ "IDS_MI_EASYFLASH_SETTINGS", "EasyFlash settings..." },
	{ "IDS_MI_SFX_SE_SETTINGS", "SFX Sound Expander settings..." },
	{ "IDS_MI_TOGGLE_SFX_SS", "Enable the SFX Sound Sampler cartridge" },
	{ "IDS_MI_TOGGLE_USERPORT_RTC", "Enable the Userport RTC expansion" },
	{ "IDS_MI_SETTINGS_SAVE_FILE", "Save current settings to specified file" },
	{ "IDS_MI_SETTINGS_LOAD_FILE", "Load settings from specified file" },
	{ "IDS_MI_SETTINGS_SAVE", "Save current settings" },
	{ "IDS_MI_SETTINGS_LOAD", "Load saved settings" },
	{ "IDS_MI_SETTINGS_DEFAULT", "Set default settings" },
	{ "IDS_MI_SAVE_SETTINGS_ON_EXIT", "Save settings on exit" },
	{ "IDS_MI_CONFIRM_ON_EXIT", "Confirm quiting VICE" },
	{ "IDS_MI_LANG_EN", "English" },
	{ "IDS_MI_LANG_DA", "Danish" },
	{ "IDS_MI_LANG_DE", "German" },
	{ "IDS_MI_LANG_ES", "Spanish" },
	{ "IDS_MI_LANG_FR", "French" },
	{ "IDS_MI_LANG_HU", "Hungarian" },
	{ "IDS_MI_LANG_IT", "Italian" },
	{ "IDS_MI_LANG_KO", "Korean" },
	{ "IDS_MI_LANG_NL", "Dutch" },
	{ "IDS_MI_LANG_PL", "Polish" },
	{ "IDS_MI_LANG_RU", "Russian" },
	{ "IDS_MI_LANG_SV", "Swedish" },
	{ "IDS_MI_LANG_TR", "Turkish" },
	{ "IDS_MI_CMDLINE", "Command line options" },
	{ "IDS_MI_CONTRIBUTORS", "Contributors" },
	{ "IDS_MI_LICENSE", "License" },
	{ "IDS_MI_WARRANTY", "No warranty!" },
	{ "IDS_MI_TOGGLE_FULLSCREEN", "Fullscreen" },
	{ "IDS_MI_SIDCART_SETTINGS", "SID cart settings..." },
	{ "IDS_MI_MON_OPEN", "Open" },
	{ "IDS_MI_MON_SAVE", "Save" },
	{ "IDS_MI_MON_PRINT", "Print" },
	{ "IDS_MI_MON_EXIT", "Exit        Alt+F4" },
	{ "IDS_MI_MON_STOP_DEBUG", "Stop Debug" },
	{ "IDS_MI_MON_STOP_EXEC", "Stop Execution" },
	{ "IDS_MI_MON_STEP_INTO", "Step into" },
	{ "IDS_MI_MON_STEP_OVER", "Step over" },
	{ "IDS_MI_MON_SKIP_RETURN", "Step until return" },
	{ "IDS_MI_MON_GOTO_CURSOR", "Go to cursor" },
	{ "IDS_MI_MON_EVAL", "Evaluate" },
	{ "IDS_MI_MON_CURRENT", "Current instruction" },
	{ "IDS_MI_MON_WND_EVAL", "Evaluation window" },
	{ "IDS_MI_MON_WND_REG", "Register window" },
	{ "IDS_MI_MON_WND_MEM", "Memory window" },
	{ "IDS_MI_MON_WND_DIS", "Disassembly window" },
	{ "IDS_MI_MON_WND_CONSOLE", "Console window" },
	{ "IDS_MI_MON_COMPUTER", "Computer" },
	{ "IDS_MI_MON_DRIVE8", "Drive 8" },
	{ "IDS_MI_MON_DRIVE9", "Drive 9" },
	{ "IDS_MI_MON_CASCADE", "Cascade" },
	{ "IDS_MI_MON_TILE_VERT", "Tile vertically" },
	{ "IDS_MI_MON_TILE_HORIZ", "Tile horizontally" },
	{ "IDS_MI_MON_ARRANGE_ICONS", "Arrange icons" },
	{ NULL, NULL }
};

static char* intl_find_text_for_res_code (int en_resource)
{
	char* res_id = NULL;

	for (int i = 0; idslist[i].str != NULL; ++i) {
		if (idslist[i].cmd == en_resource) {
			res_id = idslist[i].str;
			break;
		}
	}

	if (res_id != NULL) {
		for (int i = 0; android_text_en[i].text_id != NULL; ++i) {
			if (strcmp (android_text_en[i].text_id, res_id) == 0) {
				return android_text_en[i].text;
			}
		}
	}

	return NULL;
}

#endif //__ANDROID__

#define countof(array) (sizeof(array) / sizeof((array)[0]))

#ifndef __ANDROID__

typedef struct windows_iso_s {
    int windows_code;
    char *iso_language_code;
    int code_page;
    int hotkey_cap;
} windows_iso_t;

/* this table holds only the currently present translation
   languages, to add a new translation look at
   http://www.unicode.org/unicode/onlinedat/languages.html
   for the corresponding windows and iso codes */

static windows_iso_t windows_to_iso[] = {
    { LANG_ENGLISH, "en", 28591, 1 },
    { LANG_DANISH, "da", 28591, 1 },
    { LANG_GERMAN, "de", 28591, 1 },
    { LANG_SPANISH, "es", 28591, 1 },
    { LANG_FRENCH, "fr", 28591, 1 },
    { LANG_HUNGARIAN, "hu", 28592, 1 },
    { LANG_ITALIAN, "it", 28591, 1 },
    { LANG_KOREAN, "it", 949, 0 },
    { LANG_DUTCH, "nl", 28591, 1 },
    { LANG_POLISH, "pl", 28592, 1 },
    { LANG_RUSSIAN, "ru", 28595, 1 },
    { LANG_SWEDISH, "sv", 28591, 1 },
    { LANG_TURKISH, "tr", 28599, 1 },
    { 0, NULL, 0, 0 }
};

static int intl_table[][countof(language_table)] = {

/* res.rc */
/* en */ { IDR_MENUMONITOR,
/* da */   IDR_MENUMONITOR_DA,    /* fuzzy */
/* de */   IDR_MENUMONITOR_DE,
/* es */   IDR_MENUMONITOR_ES,    /* fuzzy */
/* fr */   IDR_MENUMONITOR_FR,
/* hu */   IDR_MENUMONITOR_HU,
/* it */   IDR_MENUMONITOR_IT,
/* ko */   IDR_MENUMONITOR_KO,    /* fuzzy */
/* nl */   IDR_MENUMONITOR_NL,
/* pl */   IDR_MENUMONITOR_PL,    /* fuzzy */
/* ru */   IDR_MENUMONITOR_RU,    /* fuzzy */
/* sv */   IDR_MENUMONITOR_SV,
/* tr */   IDR_MENUMONITOR_TR },  /* fuzzy */

};

#endif //__ANDROID__

/* --------------------------------------------------------------------- */

/* codepage 28591 (ISO 8859-1) to current codepage conversion tables */

static char cp28591[256];

static const WCHAR wcp28591[256] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
    0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
    0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f,
    0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7,
    0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af,
    0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
    0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
    0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7,
    0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
    0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7,
    0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00df,
    0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7,
    0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
    0x00f0, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7,
    0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff
};


/* codepage 28592 (ISO 8859-2) to current codepage conversion tables */

static char cp28592[256];

static const WCHAR wcp28592[256] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
    0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
    0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f,
    0x00a0, 0x0104, 0x02d8, 0x0141, 0x00a4, 0x013d, 0x015a, 0x00a7,
    0x00a8, 0x0160, 0x015e, 0x0164, 0x0179, 0x00ad, 0x017d, 0x017b,
    0x00b0, 0x0105, 0x02db, 0x0142, 0x00b4, 0x013e, 0x015b, 0x02c7,
    0x00b8, 0x0161, 0x015f, 0x0165, 0x017a, 0x02dd, 0x017e, 0x017c,
    0x0154, 0x00c1, 0x00c2, 0x0102, 0x00c4, 0x0139, 0x0106, 0x00c7,
    0x010c, 0x00c9, 0x0118, 0x00cb, 0x011a, 0x00cd, 0x00ce, 0x010e,
    0x0110, 0x0143, 0x0147, 0x00d3, 0x00d4, 0x0150, 0x00d6, 0x00d7,
    0x0158, 0x016e, 0x00da, 0x0170, 0x00dc, 0x00dd, 0x0162, 0x00df,
    0x0155, 0x00e1, 0x00e2, 0x0103, 0x00e4, 0x013a, 0x0107, 0x00e7,
    0x010d, 0x00e9, 0x0119, 0x00eb, 0x011b, 0x00ed, 0x00ee, 0x010f,
    0x0111, 0x0144, 0x0148, 0x00f3, 0x00f4, 0x0151, 0x00f6, 0x00f7,
    0x0159, 0x016f, 0x00fa, 0x0171, 0x00fc, 0x00fd, 0x0163, 0x02d9
};


/* codepage 28595 (ISO 8859-5) to current codepage conversion tables */

static char cp28595[256];

static const WCHAR wcp28595[256] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
    0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
    0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f,
    0x00a0, 0x0401, 0x0402, 0x0403, 0x0404, 0x0405, 0x0406, 0x0407,
    0x0408, 0x0409, 0x040a, 0x040b, 0x040c, 0x00ad, 0x040e, 0x040f,
    0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
    0x0418, 0x0419, 0x041a, 0x041b, 0x041c, 0x041d, 0x041e, 0x041f,
    0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
    0x0428, 0x0429, 0x042a, 0x042b, 0x042c, 0x042d, 0x042e, 0x042f,
    0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
    0x0438, 0x0439, 0x043a, 0x043b, 0x043c, 0x043d, 0x043e, 0x043f,
    0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
    0x0448, 0x0449, 0x044a, 0x044b, 0x044c, 0x044d, 0x044e, 0x044f,
    0x2116, 0x0451, 0x0452, 0x0453, 0x0454, 0x0455, 0x0456, 0x0457,
    0x0458, 0x0459, 0x045a, 0x045b, 0x045c, 0x00a7, 0x045e, 0x045f
};


/* codepage 28599 (ISO 8859-9) to current codepage conversion tables */

static char cp28599[256];

static const WCHAR wcp28599[256] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x000a, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
    0x0018, 0x0019, 0x001a, 0x001b, 0x001c, 0x001d, 0x001e, 0x001f,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
    0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
    0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
    0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
    0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
    0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
    0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x007f,
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
    0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f,
    0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7,
    0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af,
    0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
    0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
    0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7,
    0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
    0x011e, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7,
    0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x0130, 0x015e, 0x00df,
    0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7,
    0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
    0x011f, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7,
    0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x0131, 0x015f, 0x00ff
};

char *intl_convert_cp(char *text, int cp)
{
    int len,i;
    char *cp_table;
    char *buffer;

    if (text == NULL) {
        return NULL;
    }
    len = (int)strlen(text);
    if (len == 0) {
        return NULL;
    }
    switch (cp) {
        case 28591:
            cp_table = cp28591;
            break;
        case 28592:
            cp_table = cp28592;
            break;
        case 28595:
            cp_table = cp28595;
            break;
        case 28599:
            cp_table = cp28599;
            break;
        default:
            cp_table = cp28591;
    }
    buffer = lib_stralloc(text);
    for (i = 0; i < len; i++) {
        buffer[i] = cp_table[(unsigned char)text[i]];
    }
    return buffer;
}

/* --------------------------------------------------------------------- */

#ifndef __ANDROID__

static int hotkeys_loaded = 0;

typedef struct windows_hotkey_s {
    char hotkey;
    int occurence;
} windows_hotkey_t;

static windows_hotkey_t windows_hotkeys[LAST_IDS + 16][countof(language_table)];

static char line_buffer[512];

#define FOUND_UNKNOWN_LINE  0
#define FOUND_EMPTY_LINE    1
#define FOUND_COMMENT_LINE  2
#define FOUND_IDS_LINE      3

static int gethotkeyline(FILE *file)
{
    char c = 0;
    int counter = 0;

    while (c != '\n' && !feof(file) && counter < 511) {
        c = fgetc(file);
        if (c != 0xd) {
            line_buffer[counter++] = c;
        }
    }
    line_buffer[counter] = 0;

    if (line_buffer[0] == 0) {
        return FOUND_EMPTY_LINE;
    }

    if (line_buffer[0] == '#') {
        return FOUND_COMMENT_LINE;
    }

    if (line_buffer[0] == 'I' && line_buffer[1] == 'D' && line_buffer[2] == 'S' && line_buffer[3] == '_') {
        return FOUND_IDS_LINE;
    }

    return FOUND_UNKNOWN_LINE;
}

static void intl_set_hotkey(void)
{
    int i = 0;
    int ids, langid;
    int occurence = 1;
    int found_string = 0;
    char *langpos = NULL;
    char *hotkeypos = NULL;
    char *occpos = NULL;

    /* get to the first 'space' */
    while (!isspace(line_buffer[i]) && line_buffer[i] != 0) {
        i++;
    }

    /* check if end-of-line */
    if (line_buffer[i] == 0) {
        return;
    }

    line_buffer[i++] = 0;

    /* skip spaces */
    while (isspace(line_buffer[i])) {
        i++;
    }

    /* check if end-of-line */
    if (line_buffer[i] == 0) {
        return;
    }

    langpos = line_buffer + i;

    /* get the the first 'space' */
    while (!isspace(line_buffer[i]) && line_buffer[i] != 0) {
        i++;
    }

    /* check if end-of-line */
    if (line_buffer[i] == 0) {
        return;
    }

    line_buffer[i++] = 0;

    /* skip spaces */
    while (isspace((unsigned char)line_buffer[i])) {
        i++;
    }

    /* check if end-of-line */
    if (line_buffer[i] == 0) {
        return;
    }

    hotkeypos = line_buffer + i;

    /* get the the first 'space' */
    while (!isspace((unsigned char)line_buffer[i]) && line_buffer[i] != 0) {
        i++;
    }

    /* get optional occurence number */
    if (line_buffer[i] != 0) {

        line_buffer[i++] = 0;

        /* skip spaces */
        while (isspace(line_buffer[i])) {
            i++;
        }
        if (line_buffer[i] != 0) {
            occpos = line_buffer + i;
        }
    }

    /* find the ids belonging to the IDS_* string */
    for (i = 0; idslist[i].str != NULL && found_string == 0; i++) {
        if (!strcmp(idslist[i].str, line_buffer)) {
            found_string = 1;
            ids = idslist[i].cmd;
        }
    }

    /* check if ids not found */
    if (found_string == 0) {
        return;
    }

    /* find the language number belonging to the language identifier string */
    if (!strcmp(langpos, "**")) {
        found_string = 1;
        langid = -1;
    } else {
        found_string = 0;
        for (i = 0; i < countof(language_table) && found_string == 0; i++) {
            if (!strcmp(language_table[i], langpos)) {
                langid = i;
                found_string = 1;
            }
        }
    }

    /* check if language found */
    if (found_string == 0) {
        return;
    }

    /* check if the hotkey is only 1 character */
    if (strlen(hotkeypos) != 1) {
        return;
    }

    /* check for the optional occurence number */
    if (occpos != NULL) {
        occurence = atoi(occpos);
    }

    /* put entry into the hotkey table */
    if (langid == -1) {
        for (i = 0; i < sizeof(language_table); i++) {
            if (windows_to_iso[i].hotkey_cap) {
                windows_hotkeys[ids][i].hotkey = hotkeypos[0];
                windows_hotkeys[ids][i].occurence = occurence;
            }
        }
    } else {
        if (windows_to_iso[langid].hotkey_cap) {
            windows_hotkeys[ids][langid].hotkey = hotkeypos[0];
            windows_hotkeys[ids][langid].occurence = occurence;
        }
    }
}

static int intl_load_hotkey_table(void)
{
    int i, j, found;
    FILE *fhotkeys;
    char *name;

    /* init table */
    for (i = 0; i < LAST_IDS; i++) {
        for (j = 0; j < countof(language_table); j++) {
            windows_hotkeys[i][j].hotkey = 0;
            windows_hotkeys[i][j].occurence = 0;
        }
    }

    name = util_concat(archdep_boot_path(), "\\", machine_name, "/win_hotkeys.vhk", NULL);
    fhotkeys = fopen(name, MODE_READ_TEXT);
    lib_free(name);
    if (fhotkeys == NULL) {
        return 0;
    }

    while (!feof(fhotkeys)) {
        found = gethotkeyline(fhotkeys);
        if (found == FOUND_IDS_LINE) {
            intl_set_hotkey();
        }
    }
    fclose(fhotkeys);
    return 1;
}

static char *intl_add_hotkey(char *text, int ids, int lang)
{
    char *ret = NULL;
    int i = 0;
    int j = 0;
    int occ = 0;

    if (windows_hotkeys[ids][lang].hotkey == 0 || text == NULL || text[0] == 0) {
        return text;
    } else {
        ret = lib_malloc(strlen(text) + 2);
        while (text[i] != 0) {
            if (text[i] == windows_hotkeys[ids][lang].hotkey) {
                occ++;
                if (occ == windows_hotkeys[ids][lang].occurence) {
                    ret[j++] = '&';
                }
            }
            ret[j++] = text[i++];
        }
        ret[j] = 0;
        lib_free(text);

        return ret;
    }
}

#endif //__ANDROID__

/* --------------------------------------------------------------------- */

static char *intl_text_table[LAST_IDS + 16][countof(language_table)];
static BYTE text_cache[(((LAST_IDS / 16) + 1) / 8) + 1];

/* It also prepares any codepage conversion tables. */

static void intl_text_init(void)
{
#ifdef __ANDROID__
	memset (intl_text_table, 0, sizeof (intl_text_table));
	memset (text_cache, 0, sizeof (text_cache));
#else //__ANDROID__
    ZeroMemory(intl_text_table, sizeof(intl_text_table));
    ZeroMemory(text_cache, sizeof(text_cache));

    /* prepare the codepage 28591 (ISO 8859-1) to current codepage conversion */
    WideCharToMultiByte(CP_ACP, 0, wcp28591, 256, cp28591, 256, NULL, NULL);

    /* prepare the codepage 28592 (ISO 8859-2) to current codepage conversion */
    WideCharToMultiByte(CP_ACP, 0, wcp28592, 256, cp28592, 256, NULL, NULL);

    /* prepare the codepage 28595 (ISO 8859-5) to current codepage conversion */
    WideCharToMultiByte(CP_ACP, 0, wcp28595, 256, cp28595, 256, NULL, NULL);

    /* prepare the codepage 28599 (ISO 8859-9) to current codepage conversion */
    WideCharToMultiByte(CP_ACP, 0, wcp28599, 256, cp28599, 256, NULL, NULL);

    /* load the hotkey table */
    hotkeys_loaded = intl_load_hotkey_table();
#endif //__ANDROID__
}

static void intl_text_free(void)
{
    unsigned int i, j;

    for (i = 0; i < countof(language_table); i++) {
        for (j = 0; j < countof(intl_text_table); j++) {
            lib_free(intl_text_table[j][i]);
        }
    }
}

#ifdef __ANDROID__

static char* intl_load_text(int en_resource, int res_code, int lang_table_index)
{
	unsigned int i;
	int j, k;
	char* hRes;

	j = (en_resource >> 4) + 1;
	for (i = 0; i < countof (language_table); i++) {
		hRes = intl_find_text_for_res_code (en_resource);
		if (hRes) {
			for (k = 0; k < 16; k++) {
				intl_text_table[((j - 1) << 4) + k][i] = lib_stralloc (hres);
			}
		} else {
			for (k = 0; k < 16; k++) {
				intl_text_table[((j - 1) << 4) + k][i] = NULL;
			}
		}
	}
	text_cache[en_resource >> 7] |= (1 << ((en_resource >> 4) & 7));
}

#else //__ANDROID__

static void intl_load_text (int en_resource)
{
	unsigned int i;
	int j, k;
	char temp_buffer[4098 * sizeof (TCHAR)];
	HRSRC hRes;
	HGLOBAL hGlob;
	WORD *p;
	int length;

	j = (en_resource >> 4) + 1;
	for (i = 0; i < countof (language_table); i++) {
		hRes = FindResourceEx (NULL, RT_STRING, MAKEINTRESOURCE (j), (WORD) MAKELANGID (windows_to_iso[i].windows_code, SUBLANG_NEUTRAL));
		if (hRes) {
			hGlob = LoadResource (NULL, hRes);
			p = LockResource (hGlob);
			for (k = 0; k < 16; k++) {
				ZeroMemory (temp_buffer, sizeof (temp_buffer));
				length = *p++;
				WideCharToMultiByte (CP_ACP, 0, p, length, temp_buffer, 4096, NULL, NULL);
				p = p + length;
				intl_text_table[((j - 1) << 4) + k][i] = lib_stralloc (temp_buffer);
				if (hotkeys_loaded) {
					intl_text_table[((j - 1) << 4) + k][i] = intl_add_hotkey (intl_text_table[((j - 1) << 4) + k][i], ((j - 1) << 4) + k, i);
				}
			}
			FreeResource (hGlob);
		} else {
			for (k = 0; k < 16; k++) {
				intl_text_table[((j - 1) << 4) + k][i] = NULL;
			}
		}
	}
	text_cache[en_resource >> 7] |= (1 << ((en_resource >> 4) & 7));
}

#endif //__ANDROID__

char *intl_translate_text(int en_resource)
{
    char *text;

    if (!(text_cache[en_resource >> 7] & (1 << ((en_resource >> 4) & 7)))) {
		intl_load_text (en_resource);
    }
    text = intl_text_table[en_resource][current_language_index];
    if (text == NULL) {
        text = intl_text_table[en_resource][0];
    }
    return text;
}

/* pre-translated main window caption text so the emulation won't
   slow down because of all the translation calls */

char *intl_speed_at_text;

/* --------------------------------------------------------------------- */

void intl_init(void)
{
    intl_text_init();
}

int intl_translate_res(int en_resource)
{
    unsigned int i;

    if (!strcmp(current_language,"en")) {
        return en_resource;
    }

    for (i = 0; i < countof(intl_table); i++) {
        if (intl_table[i][0] == en_resource) {
            return intl_table[i][current_language_index];
        }
    }
    return en_resource;
}

void intl_shutdown(void)
{
    intl_text_free();
}

/* --------------------------------------------------------------------- */

static void intl_update_pre_translated_text(void)
{
    intl_speed_at_text=intl_translate_text(IDS_S_AT_D_SPEED);
}

char *intl_arch_language_init(void)
{
/* unused current language recognition code */
#if 0
    int i;
    WORD winlang;

    winlang = GetUserDefaultLangID() & 0x3ff;
    for (i = 0; windows_to_iso[i].iso_language_code != NULL; i++) {
        if (windows_to_iso[i].windows_code == winlang) {
            return windows_to_iso[i].iso_language_code;
        }
    }
#endif
    return "en";
}

void intl_update_ui(void)
{
    intl_update_pre_translated_text();
    ui_update_menu();
}
