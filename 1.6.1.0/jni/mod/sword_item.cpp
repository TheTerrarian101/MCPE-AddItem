#include "sword_item.h"

#include "minecraftpe/world/item/VanillaItems.h"

SwordItem::SwordItem(std::string const& nameId, short id) : Item(nameId, id) {
  setMaxStackSize(1);
  setCategory(CreativeItemCategory::EQUIPMENT);
  setMaxDamage(472);
  setHandEquipped();
}

bool SwordItem::canDestroySpecial(Block const& block) const {
  return VanillaItems::mSword_iron -> canDestroySpecial(block);
}

int SwordItem::getAttackDamage() const {
  return 10;
}

bool SwordItem::canDestroyInCreative() const {
  return false;
}

int SwordItem::getEnchantSlot() const {
  return VanillaItems::mSword_iron -> getEnchantSlot();
}

int SwordItem::getEnchantValue() const {
  return 60;
}

void SwordItem::hurtEnemy(ItemInstance& item, Mob* mob1, Mob* mob2) const {
  return VanillaItems::mSword_iron -> hurtEnemy(item, mob1, mob2);
}

void SwordItem::mineBlock(ItemInstance& item, Block const& block, int x, int y, int z, Actor* actor) const {
  return VanillaItems::mSword_iron -> mineBlock(item, block, x, y, z, actor);
}