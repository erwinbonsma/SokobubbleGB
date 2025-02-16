#include "SoundFx.h"

namespace Gamebuino_Meta {

const NoteSpec sfxPushStartNotes[1] = {
    NoteSpec { .note=Note::C6, .vol=2, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
};
const TuneSpec sfxPushStart = TuneSpec {
    .noteDuration = 1, .loopStart = 32, .numNotes = 1, .notes = sfxPushStartNotes
};

const NoteSpec sfxNoCanDoNotes[2] = {
    NoteSpec { .note=Note::D4, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
};
const TuneSpec sfxNoCanDo = TuneSpec {
    .noteDuration = 2, .loopStart = 32, .numNotes = 2, .notes = sfxNoCanDoNotes
};

const NoteSpec sfxGiveUpNotes[4] = {
    NoteSpec { .note=Note::E4, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
};
const TuneSpec sfxGiveUp = TuneSpec {
    .noteDuration = 20, .loopStart = 32, .numNotes = 4, .notes = sfxGiveUpNotes
};

const NoteSpec sfxBoxPlacedNotes[2] = {
    NoteSpec { .note=Note::F5, .vol=6, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A5, .vol=6, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
};
const TuneSpec sfxBoxPlaced = TuneSpec {
    .noteDuration = 4, .loopStart = 32, .numNotes = 2, .notes = sfxBoxPlacedNotes
};

const NoteSpec sfxLevelDoneNotes[9] = {
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::D5, .vol=4, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::D5, .vol=4, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::C6, .vol=4, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::C6, .vol=3, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::C6, .vol=3, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
};
const TuneSpec sfxLevelDone = TuneSpec {
    .noteDuration = 8, .loopStart = 32, .numNotes = 9, .notes = sfxLevelDoneNotes
};

const NoteSpec sfxBubbleChangeNotes[3] = {
    NoteSpec { .note=Note::Fs4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G5, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::Fs4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::SLIDE },
};
const TuneSpec sfxBubbleChange = TuneSpec {
    .noteDuration = 3, .loopStart = 32, .numNotes = 3, .notes = sfxBubbleChangeNotes
};

const NoteSpec sfxGetReadyNotes[16] = {
    NoteSpec { .note=Note::C4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::C4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::C4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::TILTED_SAW, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F4, .vol=4, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F4, .vol=3, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F4, .vol=3, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F4, .vol=3, .wav=WaveForm::TILTED_SAW, .fx=Effect::FADE_OUT },
};

const TuneSpec sfxGetReady = TuneSpec {
    .noteDuration = 3, .loopStart = 32, .numNotes = 16, .notes = sfxGetReadyNotes
};

const NoteSpec sfxUndoNotes[3] = {
    NoteSpec { .note=Note::B4, .vol=5, .wav=WaveForm::TILTED_SAW, .fx=Effect::FADE_IN },
    NoteSpec { .note=Note::B3, .vol=6, .wav=WaveForm::TILTED_SAW, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::B2, .vol=5, .wav=WaveForm::TILTED_SAW, .fx=Effect::FADE_OUT },
};
const TuneSpec sfxUndo = TuneSpec {
    .noteDuration = 4, .loopStart = 32, .numNotes = 3, .notes = sfxUndoNotes
};

const NoteSpec sfxNewHiNotes[16] = {
    NoteSpec { .note=Note::E4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::F4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::F4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::F4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::NONE },
    NoteSpec { .note=Note::F4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::G4, .vol=7, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=7, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::F4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::F4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=6, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
};
const TuneSpec sfxNewHi = TuneSpec {
    .noteDuration = 8, .loopStart = 32, .numNotes = 16, .notes = sfxNewHiNotes
};

} // Namespace

const Gamebuino_Meta::TuneSpec* noCanDoSfx = &Gamebuino_Meta::sfxNoCanDo;
const Gamebuino_Meta::TuneSpec* pushStartSfx = &Gamebuino_Meta::sfxPushStart;
const Gamebuino_Meta::TuneSpec* giveUpSfx = &Gamebuino_Meta::sfxGiveUp;
const Gamebuino_Meta::TuneSpec* boxPlacedSfx = &Gamebuino_Meta::sfxBoxPlaced;
const Gamebuino_Meta::TuneSpec* levelDoneSfx = &Gamebuino_Meta::sfxLevelDone;
const Gamebuino_Meta::TuneSpec* bubbleChangeSfx = &Gamebuino_Meta::sfxBubbleChange;
const Gamebuino_Meta::TuneSpec* getReadySfx = &Gamebuino_Meta::sfxGetReady;
const Gamebuino_Meta::TuneSpec* newHiSfx = &Gamebuino_Meta::sfxNewHi;
