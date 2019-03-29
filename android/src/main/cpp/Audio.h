#ifndef AUDIO
#define AUDIO

#include <SuperpoweredAdvancedAudioPlayer.h>
#include <SuperpoweredReverb.h>
#include <SuperpoweredEcho.h>
#include <AndroidIO/SuperpoweredAndroidAudioIO.h>

class Audio {
	public:
        Audio(unsigned int sampleRate, unsigned int bufferSize, const char *filePath, int fileLength);
        ~Audio();

        bool process(short int *output, unsigned int numberOfSamples);
        void play();
        void pause();

        void setEcho(float mix);
		void setPitchShift(int pitchShift);

	private:
        SuperpoweredAndroidAudioIO *audioSystem;
        SuperpoweredAdvancedAudioPlayer *playerA;
        SuperpoweredEcho *echo;

        float *stereoBuffer, echoMix;
        int pitchShift;
};

#endif
