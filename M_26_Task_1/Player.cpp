#include "Player.h"

Player::Player() {
	for (int i = 0; i < MAX_TRACKS; i++) {		
		Track* tTmp = new Track(SONG + std::to_string(i));
		std::pair<std::string, Track> pTmp(tTmp->getNameTrack(), *tTmp);
		m_player.insert(pTmp);
	}
}

void Player::ShowPlayList() {

	std::string status;	
	for (std::map<std::string, Track>::iterator it = m_player.begin(); it != m_player.end(); it++) {
		status = (it->second.getPlay() ? "Play" : "Stop");
		if (it->second.getPause() == true) status = "Pause";
		std::cout << it->first
			<< " "
			<< std::put_time(it->second.getDateTrack(), "%d-%m-%Y")
			<< " "
			<< status
			<< " "
			<< it->second.getDurationTrack()			
			<< std::endl;
	}	
}

void Player::PlaySong(std::string nameSong) {
	auto it = m_player.find(nameSong);
	if (it == m_player.end())
		std::cout << "\nTrack not found!\n";
	else if(!it->second.getPlay()) {
		std::cout << std::endl 
			<< "The track is being played " << it->first
			<< " "
			<< std::put_time(it->second.getDateTrack(), "%d-%m-%Y")
			<< " "
			<< it->second.getDurationTrack()
			<< std::endl
			<< std::endl;
		it->second.setPlay();
	}
}

void Player::PauseSong(std::string nameSong) {
	auto it = m_player.find(nameSong);
	if (it == m_player.end())
		std::cout << "\nTrack not found!\n";
	else if (it->second.getPlay()) {
		it->second.setPause();
		std::cout << std::endl 
			      << it->second.getNameTrack()
			      << " " 
			      << "Pause"
			      << std::endl
			      << std::endl;
	}
		
}

void Player::StopSong(std::string nameSong) {
	auto it = m_player.find(nameSong);
	if (it == m_player.end())
		std::cout << "\nTrack not found!\n";
	else {
		it->second.setPlay(false);
		std::cout << std::endl
			<< it->second.getNameTrack()
			<< " "
			<< "Stop"
			<< std::endl
			<< std::endl;
	}
}

void Player::NextSong() {

	//int tmp = 0 + rand() % MAX_TRACKS;
	std::map<std::string, Track>::iterator itOld = m_player.begin();
	for (; itOld != m_player.end(); itOld++) {
		if (itOld->second.getPlay() == true)
			itOld->second.setPlay(false);
	}
	std::map<std::string, Track>::iterator itNew = m_player.begin();
	while (true)
	{
		itNew = m_player.find(SONG + std::to_string(0 + rand() % MAX_TRACKS));
		if (itNew != itOld) {
			itNew->second.setPlay();
			return;
		}			
	}	
}


