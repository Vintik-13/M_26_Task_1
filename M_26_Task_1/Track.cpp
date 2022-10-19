#include "Track.h"

//Рандомное число в диапазоне min-max
int rangomNumberRange(int min, int max) {
	return min + rand() % max;
}

//Рандомная дата
std::tm* creatDate()
{
	std::time_t t = std::time(nullptr);
	std::tm* lDate = std::localtime(&t);
	std::tm tmp{};

	lDate->tm_year = rangomNumberRange(0, lDate->tm_year);

	std::vector<int> months{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((lDate->tm_year % 4 == 0 && lDate->tm_year % 100 != 100) || lDate->tm_year % 400 == 0)
		months[1] = 29;

	lDate->tm_mon = rangomNumberRange(0, 11);
	lDate->tm_mday = months[lDate->tm_mon];
	return lDate;
}

Track::Track() {
	m_nameTrack = "";
	m_durationTrack;
}

Track::Track(std::string nameTrack) {	
	m_nameTrack = nameTrack;
	m_durationTrack = rangomNumberRange(MINDTRACK, MAXDTRACK);
	m_dateTrack = *(creatDate());
}

std::string Track::getNameTrack() {
	return m_nameTrack;
}

std::tm* Track::getDateTrack() {
	return &m_dateTrack;
}

int Track::getDurationTrack() {
	return m_durationTrack;
}

bool Track::getPlay() {
	return m_play;
}

bool Track::getPause() {
	return m_pause;
}

void Track::setPlay(bool play) {
	if (m_play == false && play == true) {
		m_play = play;
		m_pause = false;
	}
	else
		m_play = play;
}

void Track::setPause(bool pause) {
	if (m_play == true && pause == true) {
		m_pause = pause;
		m_play = false;
	}
	else
		m_pause = pause;
}


