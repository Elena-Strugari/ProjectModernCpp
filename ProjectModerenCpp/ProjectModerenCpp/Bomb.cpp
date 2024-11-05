#include "Bomb.h"
#include<cmath>
#include"Position.h"
void Bomb::Explode(Position m_bombPosition,Map map)
{
    
    //for (int i = std::max(0, m_bombPosition.x - 5); i <= std::min(/* rows-1,*/ m_bombPosition.x + 5);i++) 
    //{
    //    for (int j = std::max(0, m_bombPosition.y - 5); j <= std::min(/* col-1,*/ m_bombPosition.y + 5); j++)
    //    {
    //        // Verifing if a point is in the bomb area
    //        if ((i - m_bombPosition.x) * (i - m_bombPosition.x) + (j - m_bombPosition.y) * (j - m_bombPosition.y) <= 25)  // in our case, radius=5
    //        {
    //            matrix[i][j] = 0;
    //        }
    //    }
    //}
    //Circle Area : pi*r*r  => to check is a point is in the circle area (i−x)*(i-x)+(j-y)*(j-y)<=r*r 
}
