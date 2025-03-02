#define DISPLAY_MODE DISPLAY_MODE_INDEX_HALFRES
#define FOLDER_NAME "Sokobubble"

//#define TARGET_WASM_EMULATOR

#ifdef TARGET_WASM_EMULATOR
  #define SOUND_FREQ 44100
  #define SOUND_MUSIC_BUFFERSIZE 2048
#else
  #define SOUND_FREQ 11025
  #define SOUND_MUSIC_BUFFERSIZE 1024
#endif

#define SOUND_CHANNELS 0
#define SOUND_ENABLE_MUSIC 1
#define SOUND_ENABLE_FX 1
