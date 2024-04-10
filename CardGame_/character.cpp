#include "character.h"
#include <QPicture>
#include <QPushButton>
#include "enemy.h"
//元素类型：火1 水2 风3 雷4 冰5 岩6 草7 物理0
//武器类型：单手剑1 弓箭2 法器3 大剑4 长枪5
Diluc::Diluc(){

    element = 1;
    weapon = 4;
    attached_e = 0;
}
void Diluc::normalAttack(AbstractEnemy *enemy)
{
    enemy->hp--;
}
void Diluc::elementalSkill(AbstractEnemy *enemy)
{
    enemy->hp--;
}
void Diluc::elementalBurst(AbstractEnemy *enemy)
{
    enemy->hp--;
}
