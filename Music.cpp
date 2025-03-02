#include "Music.h"

bool musicOn = false;

void playMusic() {
  if (!musicOn) {
    toggleMusic();
  }
}

void toggleMusic() {
  musicOn = !musicOn;
  if (musicOn) {
    gb.sound.playSong(song, true);
  } else {
    gb.sound.stopSong();
  }
}

namespace Gamebuino_Meta {

const NoteSpec sfx10Notes[32] = {
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
};
const TuneSpec sfx10 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx10Notes
};
const NoteSpec sfx11Notes[32] = {
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx11 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx11Notes
};
const NoteSpec sfx12Notes[32] = {
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::B3, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::B3, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A3, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A3, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    SILENCE,
    SILENCE,
};
const TuneSpec sfx12 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx12Notes
};
const NoteSpec sfx13Notes[32] = {
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx13 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx13Notes
};
const NoteSpec sfx14Notes[32] = {
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    SILENCE,
    SILENCE,
};
const TuneSpec sfx14 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx14Notes
};
const NoteSpec sfx15Notes[32] = {
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::G5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::G5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx15 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx15Notes
};
const NoteSpec sfx16Notes[32] = {
    NoteSpec { .note=Note::A4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::A4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::G4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::D4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::D4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::D4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    NoteSpec { .note=Note::E4, .vol=2, .wav=WaveForm::ORGAN, .fx=Effect::VIBRATO },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx16 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx16Notes
};
const NoteSpec sfx17Notes[32] = {
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::G5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
};
const TuneSpec sfx17 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx17Notes
};
const NoteSpec sfx18Notes[32] = {
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
};
const TuneSpec sfx18 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx18Notes
};
const NoteSpec sfx19Notes[32] = {
    NoteSpec { .note=Note::F2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    NoteSpec { .note=Note::D2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::D2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::D2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::D2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::B2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::B2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::B2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::B2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::B2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    NoteSpec { .note=Note::C3, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::C3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::C3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::C3, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx19 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx19Notes
};
const NoteSpec sfx20Notes[32] = {
    NoteSpec { .note=Note::F2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::F2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::G2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::E2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::SLIDE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx20 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx20Notes
};
const NoteSpec sfx21Notes[32] = {
    NoteSpec { .note=Note::F3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::G3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx21 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx21Notes
};
const NoteSpec sfx22Notes[32] = {
    NoteSpec { .note=Note::F3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::D4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=3, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx22 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx22Notes
};
const NoteSpec sfx23Notes[32] = {
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx23 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx23Notes
};
const NoteSpec sfx24Notes[32] = {
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=2, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=2, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    SILENCE,
};
const TuneSpec sfx24 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx24Notes
};
const NoteSpec sfx25Notes[32] = {
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=7, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::G2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::D3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::FADE_OUT },
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
};
const TuneSpec sfx25 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx25Notes
};
const NoteSpec sfx26Notes[32] = {
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx26 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx26Notes
};
const NoteSpec sfx27Notes[32] = {
    NoteSpec { .note=Note::E4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::D4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::B3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::C4, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    NoteSpec { .note=Note::A3, .vol=5, .wav=WaveForm::ORGAN, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
    SILENCE,
};
const TuneSpec sfx27 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx27Notes
};
const NoteSpec sfx28Notes[32] = {
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::D5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::B5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E5, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=5, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::C6, .vol=2, .wav=WaveForm::PHASER, .fx=Effect::FADE_OUT },
};
const TuneSpec sfx28 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx28Notes
};
const NoteSpec sfx29Notes[32] = {
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=5, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=3, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=5, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=3, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A3, .vol=2, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::NOISE, .fx=Effect::FADE_OUT },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
    NoteSpec { .note=Note::E2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::DROP },
};
const TuneSpec sfx29 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx29Notes
};
const NoteSpec sfx30Notes[32] = {
    NoteSpec { .note=Note::F2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::D2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::B2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::B2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::G3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::C2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
};
const TuneSpec sfx30 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx30Notes
};
const NoteSpec sfx31Notes[32] = {
    NoteSpec { .note=Note::F2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::F3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::F3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::G2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::E2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::B2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=6, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    SILENCE,
    SILENCE,
    NoteSpec { .note=Note::A2, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::A2, .vol=3, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::B2, .vol=5, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::C3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::D3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
    NoteSpec { .note=Note::E3, .vol=4, .wav=WaveForm::TRIANGLE, .fx=Effect::NONE },
};
const TuneSpec sfx31 = TuneSpec {
    .noteDuration = 22, .loopStart = 32, .numNotes = 32, .notes = sfx31Notes
};

const TuneSpec *const pattern0Tunes[3] = { &sfx10, &sfx11, &sfx12 };
const PatternSpec pattern0 = PatternSpec {
    .numTunes = 3, .tunes = pattern0Tunes
};
const TuneSpec *const pattern1Tunes[3] = { &sfx10, &sfx11, &sfx14 };
const PatternSpec pattern1 = PatternSpec {
    .numTunes = 3, .tunes = pattern1Tunes
};
const TuneSpec *const pattern2Tunes[4] = { &sfx10, &sfx11, &sfx12, &sfx13 };
const PatternSpec pattern2 = PatternSpec {
    .numTunes = 4, .tunes = pattern2Tunes
};
const TuneSpec *const pattern3Tunes[4] = { &sfx10, &sfx11, &sfx14, &sfx15 };
const PatternSpec pattern3 = PatternSpec {
    .numTunes = 4, .tunes = pattern3Tunes
};
const TuneSpec *const pattern4Tunes[3] = { &sfx10, &sfx11, &sfx16 };
const PatternSpec pattern4 = PatternSpec {
    .numTunes = 3, .tunes = pattern4Tunes
};
const PatternSpec pattern5 = PatternSpec {
    .numTunes = 3, .tunes = pattern4Tunes
};
const TuneSpec *const pattern6Tunes[4] = { &sfx18, &sfx19, &sfx16, &sfx17 };
const PatternSpec pattern6 = PatternSpec {
    .numTunes = 4, .tunes = pattern6Tunes
};
const TuneSpec *const pattern7Tunes[4] = { &sfx18, &sfx20, &sfx16, &sfx17 };
const PatternSpec pattern7 = PatternSpec {
    .numTunes = 4, .tunes = pattern7Tunes
};
const TuneSpec *const pattern8Tunes[4] = { &sfx18, &sfx19, &sfx21, &sfx17 };
const PatternSpec pattern8 = PatternSpec {
    .numTunes = 4, .tunes = pattern8Tunes
};
const TuneSpec *const pattern9Tunes[4] = { &sfx18, &sfx20, &sfx22, &sfx17 };
const PatternSpec pattern9 = PatternSpec {
    .numTunes = 4, .tunes = pattern9Tunes
};
const TuneSpec *const pattern10Tunes[4] = { &sfx18, &sfx19, &sfx21, &sfx23 };
const PatternSpec pattern10 = PatternSpec {
    .numTunes = 4, .tunes = pattern10Tunes
};
const TuneSpec *const pattern11Tunes[4] = { &sfx18, &sfx20, &sfx22, &sfx23 };
const PatternSpec pattern11 = PatternSpec {
    .numTunes = 4, .tunes = pattern11Tunes
};
const TuneSpec *const pattern12Tunes[3] = { &sfx18, &sfx19, &sfx12 };
const PatternSpec pattern12 = PatternSpec {
    .numTunes = 3, .tunes = pattern12Tunes
};
const TuneSpec *const pattern13Tunes[3] = { &sfx18, &sfx20, &sfx14 };
const PatternSpec pattern13 = PatternSpec {
    .numTunes = 3, .tunes = pattern13Tunes
};
const TuneSpec *const pattern14Tunes[4] = { &sfx18, &sfx19, &sfx16, &sfx13 };
const PatternSpec pattern14 = PatternSpec {
    .numTunes = 4, .tunes = pattern14Tunes
};
const TuneSpec *const pattern15Tunes[4] = { &sfx18, &sfx20, &sfx16, &sfx15 };
const PatternSpec pattern15 = PatternSpec {
    .numTunes = 4, .tunes = pattern15Tunes
};
const TuneSpec *const pattern16Tunes[3] = { &sfx24, &sfx25, &sfx12 };
const PatternSpec pattern16 = PatternSpec {
    .numTunes = 3, .tunes = pattern16Tunes
};
const TuneSpec *const pattern17Tunes[3] = { &sfx24, &sfx25, &sfx14 };
const PatternSpec pattern17 = PatternSpec {
    .numTunes = 3, .tunes = pattern17Tunes
};
const TuneSpec *const pattern18Tunes[4] = { &sfx24, &sfx25, &sfx16, &sfx17 };
const PatternSpec pattern18 = PatternSpec {
    .numTunes = 4, .tunes = pattern18Tunes
};
const PatternSpec pattern19 = PatternSpec {
    .numTunes = 4, .tunes = pattern18Tunes
};
const TuneSpec *const pattern20Tunes[4] = { &sfx18, &sfx25, &sfx21, &sfx23 };
const PatternSpec pattern20 = PatternSpec {
    .numTunes = 4, .tunes = pattern20Tunes
};
const TuneSpec *const pattern21Tunes[4] = { &sfx18, &sfx25, &sfx22, &sfx23 };
const PatternSpec pattern21 = PatternSpec {
    .numTunes = 4, .tunes = pattern21Tunes
};
const TuneSpec *const pattern22Tunes[4] = { &sfx24, &sfx25, &sfx26, &sfx23 };
const PatternSpec pattern22 = PatternSpec {
    .numTunes = 4, .tunes = pattern22Tunes
};
const TuneSpec *const pattern23Tunes[4] = { &sfx24, &sfx25, &sfx27, &sfx23 };
const PatternSpec pattern23 = PatternSpec {
    .numTunes = 4, .tunes = pattern23Tunes
};
const TuneSpec *const pattern24Tunes[3] = { &sfx24, &sfx30, &sfx12 };
const PatternSpec pattern24 = PatternSpec {
    .numTunes = 3, .tunes = pattern24Tunes
};
const TuneSpec *const pattern25Tunes[3] = { &sfx24, &sfx31, &sfx14 };
const PatternSpec pattern25 = PatternSpec {
    .numTunes = 3, .tunes = pattern25Tunes
};
const TuneSpec *const pattern26Tunes[4] = { &sfx24, &sfx30, &sfx12, &sfx13 };
const PatternSpec pattern26 = PatternSpec {
    .numTunes = 4, .tunes = pattern26Tunes
};
const TuneSpec *const pattern27Tunes[4] = { &sfx24, &sfx31, &sfx14, &sfx15 };
const PatternSpec pattern27 = PatternSpec {
    .numTunes = 4, .tunes = pattern27Tunes
};
const TuneSpec *const pattern28Tunes[3] = { &sfx29, &sfx30, &sfx12 };
const PatternSpec pattern28 = PatternSpec {
    .numTunes = 3, .tunes = pattern28Tunes
};
const TuneSpec *const pattern29Tunes[3] = { &sfx29, &sfx31, &sfx14 };
const PatternSpec pattern29 = PatternSpec {
    .numTunes = 3, .tunes = pattern29Tunes
};
const TuneSpec *const pattern30Tunes[4] = { &sfx29, &sfx30, &sfx12, &sfx17 };
const PatternSpec pattern30 = PatternSpec {
    .numTunes = 4, .tunes = pattern30Tunes
};
const TuneSpec *const pattern31Tunes[4] = { &sfx29, &sfx31, &sfx14, &sfx17 };
const PatternSpec pattern31 = PatternSpec {
    .numTunes = 4, .tunes = pattern31Tunes
};
const TuneSpec *const pattern32Tunes[4] = { &sfx29, &sfx25, &sfx21, &sfx28 };
const PatternSpec pattern32 = PatternSpec {
    .numTunes = 4, .tunes = pattern32Tunes
};
const TuneSpec *const pattern33Tunes[4] = { &sfx29, &sfx25, &sfx22, &sfx28 };
const PatternSpec pattern33 = PatternSpec {
    .numTunes = 4, .tunes = pattern33Tunes
};
const TuneSpec *const pattern34Tunes[4] = { &sfx29, &sfx25, &sfx26, &sfx28 };
const PatternSpec pattern34 = PatternSpec {
    .numTunes = 4, .tunes = pattern34Tunes
};
const TuneSpec *const pattern35Tunes[4] = { &sfx29, &sfx25, &sfx27, &sfx28 };
const PatternSpec pattern35 = PatternSpec {
    .numTunes = 4, .tunes = pattern35Tunes
};
const TuneSpec *const pattern36Tunes[4] = { &sfx29, &sfx19, &sfx16, &sfx13 };
const PatternSpec pattern36 = PatternSpec {
    .numTunes = 4, .tunes = pattern36Tunes
};
const TuneSpec *const pattern37Tunes[4] = { &sfx29, &sfx20, &sfx16, &sfx15 };
const PatternSpec pattern37 = PatternSpec {
    .numTunes = 4, .tunes = pattern37Tunes
};
const TuneSpec *const pattern38Tunes[3] = { &sfx29, &sfx19, &sfx16 };
const PatternSpec pattern38 = PatternSpec {
    .numTunes = 3, .tunes = pattern38Tunes
};
const TuneSpec *const pattern39Tunes[3] = { &sfx29, &sfx20, &sfx16 };
const PatternSpec pattern39 = PatternSpec {
    .numTunes = 3, .tunes = pattern39Tunes
};
const TuneSpec *const pattern40Tunes[3] = { &sfx18, &sfx19, &sfx16 };
const PatternSpec pattern40 = PatternSpec {
    .numTunes = 3, .tunes = pattern40Tunes
};
const TuneSpec *const pattern41Tunes[3] = { &sfx18, &sfx20, &sfx16 };
const PatternSpec pattern41 = PatternSpec {
    .numTunes = 3, .tunes = pattern41Tunes
};
const TuneSpec *const pattern42Tunes[4] = { &sfx18, &sfx19, &sfx16, &sfx17 };
const PatternSpec pattern42 = PatternSpec {
    .numTunes = 4, .tunes = pattern42Tunes
};
const TuneSpec *const pattern43Tunes[4] = { &sfx18, &sfx20, &sfx16, &sfx17 };
const PatternSpec pattern43 = PatternSpec {
    .numTunes = 4, .tunes = pattern43Tunes
};

const PatternSpec *const songPatterns[42] = {
    &pattern0,
    &pattern1,
    &pattern2,
    &pattern3,
    &pattern4,
    &pattern5,
    &pattern6,
    &pattern7,
    &pattern8,
    &pattern9,
    &pattern10,
    &pattern11,
    &pattern12,
    &pattern13,
    &pattern14,
    &pattern15,
    &pattern16,
    &pattern17,
    &pattern18,
    &pattern19,
    &pattern20,
    &pattern21,
    &pattern22,
    &pattern23,
    &pattern24,
    &pattern25,
    &pattern26,
    &pattern27,
    &pattern28,
    &pattern29,
    &pattern30,
    &pattern31,
    &pattern32,
    &pattern33,
    &pattern34,
    &pattern35,
    &pattern36,
    &pattern37,
    &pattern38,
    &pattern39,
    &pattern40,
    &pattern41,
};
const SongSpec song = SongSpec {
    .loopStart = 6, .numPatterns = 42, .patterns = songPatterns
};

} // end namespace

const Gamebuino_Meta::SongSpec* song = &Gamebuino_Meta::song;


