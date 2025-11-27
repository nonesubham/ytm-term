// #define MINIAUDIO_IMPLEMENTATION
// #include <miniaudio/miniaudio.h>
// #include <iostream>
// #include <string>

// int main()
// {
//     ma_result result;
//     ma_engine engine;

//     result = ma_engine_init(nullptr, &engine);
//     if (result != MA_SUCCESS)
//         return -1;

//     std::string filePath;
//     std::cout << "Enter sound path: ";
//     std::getline(std::cin, filePath);
//     if (ma_engine_play_sound(&engine, filePath.c_str(), nullptr) !=
//     MA_SUCCESS)
//         std::cerr << "Could not play sound\n";

//     std::cout << "Press Enter to quit...";
//     std::cin.get();

//     ma_engine_uninit(&engine);
//     return 0;
// }

// #define MINIAUDIO_IMPLEMENTATION
// #include <iostream>
// #include <miniaudio/miniaudio.h>
// #include <string>

// struct Sound {
//   ma_decoder decoder;
//   bool finished;
// };


// void data_callback(ma_device *pDevice, void *pOutput, const void *, ma_uint32 frameCount) {
  
//   Sound *snd = (Sound *)(pDevice->pUserData);
  
//   if (snd == nullptr || snd->finished) {


//     memset(pOutput, 0,frameCount * pDevice->playback.channels * ma_get_bytes_per_sample(pDevice->playback.format));
//     return;
//   }

//   /* try to read <frameCount> frames */
//   ma_uint64 framesRead = 0;

//   if (ma_decoder_read_pcm_frames(&snd->decoder, pOutput, frameCount,
//                                  &framesRead) != MA_SUCCESS)
//     framesRead = 0;

//   if (framesRead < frameCount) { /* hit EOF */
//     memset(static_cast<char *>(pOutput) +
//                framesRead * pDevice->playback.channels *
//                    ma_get_bytes_per_sample(pDevice->playback.format),
//            0,
//            (frameCount - framesRead) * pDevice->playback.channels *
//                ma_get_bytes_per_sample(pDevice->playback.format));
//     snd->finished = true;
//   }
// }

// int main() {
//   std::string filePath;
//   std::cout << "Enter sound path: ";
//   std::getline(std::cin, filePath);

//   Sound snd{};
//   if (ma_decoder_init_file(filePath.c_str(), nullptr, &snd.decoder) !=
//       MA_SUCCESS) {
//     std::cerr << "Could not load file\n";
//     return -1;
//   }

//   ma_device_config config = ma_device_config_init(ma_device_type_playback);
//   config.playback.format = snd.decoder.outputFormat;
//   config.playback.channels = snd.decoder.outputChannels;
//   config.sampleRate = snd.decoder.outputSampleRate;
//   config.dataCallback = data_callback;
//   config.pUserData = &snd;

//   ma_device device;
//   if (ma_device_init(nullptr, &config, &device) != MA_SUCCESS) {
//     std::cerr << "Failed to open playback device\n";
//     ma_decoder_uninit(&snd.decoder);
//     return -1;
//   }

//   snd.finished = false;
//   ma_device_start(&device);

//   std::cout << "Playing (press Enter to stop)...\n";
//   std::cin.get();

//   ma_device_uninit(&device);
//   ma_decoder_uninit(&snd.decoder);
//   return 0;
// }




// #include <cstdio>
// #include <iostream>
// #define MA_IMPLEMENTATION
// #include <miniaudio/miniaudio.h>



// int main(void)
// {
//     ma_result   rc;
//     ma_engine   engine;
//     ma_sound sound;

//     /* 1) Start the engine (NULL = use default device) */
//     rc = ma_engine_init(NULL, &engine);
//     if (rc != MA_SUCCESS) {
//         printf("ERROR: engine init failed (%d)\n", rc);
//         return -1;
//     }

// ma_sound_init_from_file(&engine, "../sound.wav", 0, NULL, NULL, &sound);
// ma_sound_start(&sound);
//     /* 3) Keep the process alive while the sound is audible */
//     printf("Press ENTER to quit...\n");
//     getchar();
//     ma_sound_set_volume(&sound, 0.2f);
//     getchar();
//     ma_sound_set_volume(&sound, 1.0f);
// getchar();

// ma_sound_stop(&sound);
// getchar();
// ma_sound_seek_to_pcm_frame(&sound, 0);
// ma_sound_start(&sound);
// getchar();
//     /* 4) Clean-up */
//     ma_sound_stop(&sound);
// ma_sound_uninit(&sound);
//     return 0;
// }



