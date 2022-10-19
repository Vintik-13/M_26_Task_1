#pragma once
#include <map>
#include <iostream>
#include <iomanip>
#include "Track.h"

const int MAX_TRACKS = 10;
const std::string SONG = "Song";
class Player {
	std::map<std::string, Track> m_player{};
public:	
	Player();
	void ShowPlayList();
	void PlaySong(std::string nameSong);
	void PauseSong(std::string nameSong);
	void StopSong(std::string nameSong);
	void NextSong();
};

