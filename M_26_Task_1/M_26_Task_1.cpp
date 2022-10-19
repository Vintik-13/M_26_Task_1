/*Задание 1. Реализация имитации аудиоплеера

Что нужно сделать
С помощью классов реализуйте программу имитации работы аудиоплеера.
В плеере находится несколько аудиозаписей, доступных для воспроизведения.
Для них вы должны создать отдельный класс Track. Полями этого класса
должны быть: название, дата создания (здесь вы можете использовать тип
std::tm) и продолжительность записи в секундах.
Сам плеер тоже реализуйте с помощью класса. Внутри он должен содержать
список доступных записей и нужные для логики работы плеера поля.
Пользователь взаимодействует с программой с помощью команд:
Команда play запрашивает у пользователя название записи для воспроизведения
и начинает её воспроизведение. Воспроизведение симулируется с помощью вывода
в консоль всей информации о записи. Если произведение какой-то записи уже
начато, ничего не происходит.
Команда pause. Ставит запись на паузу, о чём выводит соответствующее
сообщение в консоль. Если запись уже на паузе или не воспроизводится вовсе,
ничего не происходит.
Команда next переходит к следующей записи для воспроизведения. Запись при
этом выбирается случайно, как будто плеер работает в режиме shuffle.
Команда stop прекращает воспроизведение текущей записи, если таковая
имеется. Об этом выводится сообщение в консоль. Два раза остановить
воспроизведение невозможно, так что команда должна срабатывать только
в первом случае.
Команда exit — выход из программы.*/

#include <iostream>
#include "Player.h"
#include "Track.h"

int main()
{
	std::srand(time(0));
	Player* my = new Player();
	std::vector<std::string> pattern{ "play", "pause", "stop", "next", "exit" };
	std::string comand;
	std::string nameSong;
	int iComand{ -1 };

	my->ShowPlayList();
	while (comand != "exit") {		
		std::cout << "\nEnter the command: \n";
		std::getline(std::cin, comand);

		for (int i = 0; i < pattern.size(); i++) {
			if (comand == pattern[i])
				iComand = i;
		}
		switch (iComand)
		{
		case 0:			
			std::cout << "\nEnter the song name: \n";
			std::getline(std::cin, nameSong);			
			my->PlaySong(nameSong);
			my->ShowPlayList();
			break;
		case 1:			
			std::cout << "\nEnter the song name: \n";
			std::getline(std::cin, nameSong);
			my->PauseSong(nameSong);
			my->ShowPlayList();
			break;
		case 2:
			std::cout << "\nEnter the song name: \n";
			std::getline(std::cin, nameSong);
			my->StopSong(nameSong);
			my->ShowPlayList();
			break;
		case 3:
			my->NextSong();
			my->ShowPlayList();
			break;
		default:
			std::cout << "Incorrect comand\n";
			break;
		}
	}	
}
	

