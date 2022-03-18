/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlegame.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:45:29 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/16 16:42:12 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLEGAME_HPP
# define CIRCLEGAME_HPP

# include <string>
# include <iostream>
# include "../raylib-cpp/include/raylib-cpp.hpp"
# include "../config.hpp"

# define START_SCREEN 0
# define LOADING_SCREEN 1
# define IN_GAME 2
# define GAME_OVER 3

const static std::string menuText[] {
	"CIRCLEGAME", "Press Enter to Play the Game!", "alpha v0.1"
};

const static int	menuTextSize[] {
	SCREEN_HEIGHT / 14, SCREEN_HEIGHT / 28, SCREEN_HEIGHT / 36
};

const static int	menuTextLen[] {
	MeasureText(menuText[0].c_str(), menuTextSize[0]), MeasureText(menuText[1].c_str(), menuTextSize[1]), MeasureText(menuText[2].c_str(), menuTextSize[2])
};

struct Data {
	raylib::Window window{SCREEN_WIDTH, SCREEN_HEIGHT, "circlegame"};
	int	screenWidth = SCREEN_WIDTH;
	int	screenHeight = SCREEN_HEIGHT;
	int	screenFPS = SCREEN_FPS;
	int	gameMode = START_SCREEN;
};

void	startScreen(Data &data);
void	loadingScreen(Data &data);

#endif