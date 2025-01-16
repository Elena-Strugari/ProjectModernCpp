export module Wall;

export class Wall {
public:
    // Enum representing the type of wall
    enum class TypeWall {
        destructible,
        indestructible,
        none
    };

    // Constructor
    Wall(TypeWall typeWall);

    // Getter
    TypeWall IsDestructible() const;

private:
    TypeWall m_typeWall;
};

// Implementation
Wall::Wall(TypeWall typeWall)
    : m_typeWall{ typeWall } {
}

Wall::TypeWall Wall::IsDestructible() const {
    return m_typeWall;
}