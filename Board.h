#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "Cell.h"
#include "Piece.h"
#define BOARD_OFFSET_X 210
#define BOARD_OFFSET_Y 50

class Board : public sf::Drawable, sf::Transformable 
{
private:
    int boardWidth;     // ������ ����
    int boardHeight;    // ������ ����
    int** board;        // ������ ����

    // �������� ������
    sf::Texture tileset = Resources::getTexture("res/tiles.png");

    // ������ ������ ����� ����� ������������ 4 ���������
    sf::VertexArray vertices;

    // ��������� �������� ������ �����
    void updateTexture(Cell piecePos, Cell shapeCell, int color, int tileSize);

    // ��������� ��� ������
    void updateAllTextures(int tileSize);
public:
    // ����������� ������
    Board(int boardWidth, int boardHeight);
    // ���������� ������
    ~Board();

    // ������� ������ ������, �������������� �����.
    // ��������� �������� �������� ����� UpdateAllTextures()
    void initialization(int tileSize);

    // �������� ������������ � ������� ��������/��������� �����
    // ���������� false, ���� ������������ �� ����������
    // ���������� true, ���� ����� �� ������ ������ ����������� � ���-����
    bool collidesWith(int x, int y, Cell* shape);
    
    // ��������� ������ �� ����� � ��������� �������� �����
    // ���������� false, ���� ���� �������� (������ ���� ��������� � ����������� ���� �� Y)
    // ���������� true, ���� ������ ���� ��������� �������
    bool add(Piece* piece);

    // ������� ����������� �����, ���������� ����� �������� �� ��� �����
    int updateBoard();

    // �������� ��� ����� ���� ��������� ����, ��������� ��������
    void pushRowDown(int row);

protected:
    // ������������ ����
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};