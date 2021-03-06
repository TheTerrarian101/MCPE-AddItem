#pragma once

#include "minecraftpe/item/Item.h"

class SwordItem : public Item {
public:
  SwordItem(std::string const&,int);

  virtual bool canDestroySpecial(Block const&) const;
  virtual int getAttackDamage() const;
  virtual bool canDestroyInCreative() const;
  virtual int getEnchantSlot() const;
  virtual int getEnchantValue() const;
  virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
  virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
  virtual void mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
};