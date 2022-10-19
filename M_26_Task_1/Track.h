#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <vector>

const int MINDTRACK = 60;
const int MAXDTRACK = 180;
const int MINYEAR = 1900;

class Track {
	std::string m_nameTrack;
	std::tm m_dateTrack{};
	int m_durationTrack;
	bool m_play = false;
	bool m_pause = false;
	
public:
	friend int rangomNumberRange(int min, int max);
	friend std::tm* creatDate();
	Track();
	Track(std::string nameTrack);
	std::string getNameTrack();
	std::tm* getDateTrack();
	int getDurationTrack();
	bool getPlay();
	bool getPause();
	void setPlay(bool play = true);
	void setPause(bool pause = true);	
};

