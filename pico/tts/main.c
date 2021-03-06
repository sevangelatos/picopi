#include "tts_engine.h"
#include <stdio.h>

bool synth_callback(void *user, uint32_t rate, uint32_t depth, int channels, uint8_t *buff, uint32_t len, bool fin)
{
	fprintf(stderr, "cb: %d/%d/%d len: %d fin:%d\n", rate, depth, channels, len, fin);
	FILE *fp = (FILE *) user;
	fwrite(buff, 1, len, fp);
	return true;
}

int main(int argc, char *argv[])
{
	const char *voiceDir = "/usr/share/pico/lang";
	const char *text = "Hello world.";
	TTS_Engine *engine = TtsEngine_Create(voiceDir, "en-GB", synth_callback);
	if (!engine) {
		fprintf(stderr, "Engine creation failed");
		return -1;
	}

	if (argc > 1) {
		text = argv[1];
	}

	fprintf(stderr, "Input string: \"%s\"\n", text);

	TtsEngine_SetPitch(engine, 100);
	TtsEngine_SetRate(engine, 100);

	if (!TtsEngine_Speak(engine, text, stdout)) {
		fprintf(stderr, "TtsEngine_Speak failed");
		TtsEngine_Destroy(engine);
		return -1;
	}

	TtsEngine_Destroy(engine);
	return 0;
}
