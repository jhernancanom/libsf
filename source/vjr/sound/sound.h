//////////
//
// /libsf/source/vjr/sound/sound.h
//
//////
// Version 0.49
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.31.2014
//////
// Change log:
//     Jul.31.2014 - Initial creation
//////
//
// This software is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// You are free to use, copy, modify and share this software.  However, it can only
// be released under the PBL version indicated, and every project must include a copy
// of the pbl.txt document for its version as is at http://www.libsf.org/licenses/.
//
// For additional information about this project, or to view the license, see:
//
//     http://www.libsf.org/
//     http://www.libsf.org/licenses/
//     http://www.visual-freepro.org
//     http://www.visual-freepro.org/blog/
//     http://www.visual-freepro.org/forum/
//     http://www.visual-freepro.org/wiki/
//     http://www.visual-freepro.org/wiki/index.php/PBL
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//









//////////
// Tone
//////
	struct _isSoundTone
	{
		u32				nMilliseconds;									// How many milliseconds to generate?
		u32				nSamplesToGenerate;								// Based on milliseconds, how many samples to generate?
		u32				nSamplesGenerated;								// How many samples have been generated thus far?

		// Tone 1
		f32				fAccumulator1;									// Accumulated value for sine wave tones
		f32				fHertz1;										// Frequency

		// Tone 2
		f32				fAccumulator2;									// Accumulated value for sine wave tones
		f32				fHertz2;										// Frequency

		// Tone 3
		f32				fAccumulator3;									// Accumulated value for sine wave tones
		f32				fHertz3;										// Frequency

		// Tone 4
		f32				fAccumulator4;									// Accumulated value for sine wave tones
		f32				fHertz4;										// Frequency
	};



//////////
// Use this function as a template for the callback function sent to sound_createStream()
//////
	struct _isSSoundCallback
	{
		union {
			u64		_callback;
			void	(WINAPI *callback)	(f32* sampleBuffer, u32 tnSamples, bool* tlContinueAfterThisSampleSet);
		};
	};



//////////
// Stream
//////
	struct _isSoundStream
	{
		_isSSoundCallback filler;									// Callback to fill our stream data
	};




//////////
// Sound
//////
	struct _isSSound
	{
		SLL				ll;												// 2-way link list
		
		// Flags
		bool			isPlaying;										// Is the stream playing?
		bool			inDeleteQueue;									// Should this item be deleted when next it stops playing?

		// Stream buffer and channel volume
		// Each sound channel populates its own samples, and then these are mixed together
		f32*			samples;										// Each sample is 0.0 to 1.0 based on its value
		f32				volume;											// How loud should this channel be (0.0f - 1.0f)

		// Shared structure based on whatever identity it has
		bool			isStream;										// Is this a sound stream? no=tone
		union {
			_isSoundStream	stream;										// Sound streams are callbacks to request sound data
			_isSoundTone	tone;										// Sound tones are combined tones computed upon demand
		};
	};




//////////
// Global variables and constants
//////
	const f32		_2PI						= (f32)M_PI * 2.0f;	// 2 * pi
	bool			glSDL_Initialized			= false;			// A global flag indicating if the SDL initialized properly
	SStartEnd		gseRootSounds;									// List of all sound objects currently known about
	SDL_AudioSpec	gsdlDesired;									// What we request of SDL
	SDL_AudioSpec	gsdlObtained;									// What SDL gives us
	u16				gnFrequency					= 44100;			// We default to 44.1 kHz (standard CD-ROM quality)
	f32				gfFrequencyMultiplier		= (f32)_2PI / 44100.0f;



//////////
// Forward declarations
//////
	void			isound_initialize			(void);
	void			isound_playControl			(bool tlShouldBePlaying);
	void			isound_sdl_callback			(void* user, Uint8* stream, int length);
	bool			isound_DeleteValidate		(SStartEndCallback* cb);
	void			isound_requestStreams		(SStartEndCallback* cb);
	void			iisound_generateTones		(_isSSound* tss, u32 tnSamples);

	// These two create functions return a handle
	u64				sound_createTone			(f32 tfHertz1, f32 tfHertz2, f32 tfHertz3, f32 tfHertz4, u32 tnDurationMilliseconds);
	u64				sound_createStream			(u32 tnSamplesPerSecond, u64 tnSoundFillerCallbackFunction);

	// These functions are used once a tone or stream was already created
	u64				sound_setVolume				(u64 tnHandle, f32 tfVolume);	// Volume in range 0..1
	u64				sound_playStart				(u64 tnHandle, f32 tfVolume);
	u64				sound_playCancel			(u64 tnHandle);
	u64				sound_deleteHandle			(u64 tnHandle);
