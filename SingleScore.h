#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <string>

class SingleScore : public sf::Drawable
{
private:
    sf::Font font = Resources::getFont("res/Exo-ExtraBold.ttf");
    sf::Text nickText;
    sf::Text scoreText;

    std::string nick;
    int score = 0;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    // �����������
    SingleScore(const std::string& nick, int score);
    // ���������� �������� ��������
    long getScore() const;
    // ������������� ������� �������� �� ������
    void update(int x, int y);
};