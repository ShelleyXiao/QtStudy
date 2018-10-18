#ifndef TETRIXSHAPE_H
#define TETRIXSHAPE_H


enum TetrixShape{
     NoShape, ZShape, SShape, LineShape,
    TShape, SQuareShape, LShape, MirroredLShape
};

class TetrixPiece {

public:
    TetrixPiece() {
        setShape(NoShape);
    }

    void setRandomShape();
    void setShape(TetrixShape shape);

    TetrixShape shape() const {
       return pieceShape;
    }

    int x(int index) const {
        return coords[index][0];
    }

    int y(int index) const {
        return coords[index][1];
    }

    int minX() const;
    int minY() const;

    int maxX() const;
    int maxY() const;

    TetrixPiece rotateLeft() const;
    TetrixPiece rotateRight() const;

private:
    void setX(int index, int x) {
        coords[index][0] = x;
    }
    void setY(int index, int y) {
        coords[index][1] = y;
    }

    TetrixShape pieceShape;
    int coords[4][2];
};

#endif // TETRIXSHAPE_H
