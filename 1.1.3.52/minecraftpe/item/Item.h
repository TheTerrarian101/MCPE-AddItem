#pragma once

/*
MCPE 1.1.0.55
*/

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "CreativeItemCategory.h"
#include "../texture/TextureUVCoordinateSet.h"
#include "../util/BlockID.h"

class ItemInstance;
class TextureUVCoordinateSet;
class UseAnimation;
class BlockShape;
class Block;
class Level;
class Player;
class BlockSource;
class Container;
class Vec3;
class Mob;
class BlockID;
class Entity;
class IDataInput;
class IDataOutput;
class BlockPos;
class TextureAtlas;
class ResourcePackManager;
class BlockSource;

namespace Json
{
    class Value;
}

typedef int CooldownType;

class Item
{
public:
    char filler[260];
public:
    Item(std::string const&, short);
public:
    virtual ~Item();
    virtual void setIcon(std::string const&, int);
    virtual void setIcon(TextureUVCoordinateSet const&);
    virtual void setMaxStackSize(unsigned char);
    virtual void setCategory(CreativeItemCategory);
    virtual void setStackedByData(bool);
    virtual void setMaxDamage(int);
    virtual void setHandEquipped();
    virtual void setUseAnimation(UseAnimation);
    virtual void setMaxUseDuration(int);
    virtual void setRequiresWorldBuilder(bool);
    virtual void setExplodable(bool);
    virtual void setIsGlint(bool);
    virtual void setShouldDespawn(bool);
    virtual BlockShape getBlockShape() const;
    virtual bool canBeDepleted() const;
    virtual bool canDestroySpecial(Block const&) const;
    virtual int getLevelDataForAuxValue(int) const;
    virtual bool isStackedByData() const;
    virtual int getMaxDamage() const;
    virtual int getAttackDamage() const;
    virtual bool isHandEquipped() const;
    virtual bool isArmor() const;
    virtual bool isDye() const;
    virtual bool isGlint(ItemInstance const&) const;
    virtual bool isThrowable() const;
    virtual bool canDestroyInCreative() const;
    virtual bool isDestructive(int) const;
    virtual bool isLiquidClipItem(int) const;
    virtual bool requiresInteract() const;
    virtual std::string& appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
    virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&) const;
    virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual bool isComplex() const;
    virtual bool isValidAuxValue(int) const;
    virtual int getDamageChance(int) const;
    virtual bool uniqueAuxValues() const;
    virtual int getColor(ItemInstance const&) const;
    virtual bool isTintable() const;
    virtual void use(ItemInstance&, Player&) const;
    virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char) const;
    virtual void useTimeDepleted(ItemInstance&, Level*, Player*) const;
    virtual void releaseUsing(ItemInstance&, Player*, int) const;
    virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
    virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
    virtual void interactEnemy(ItemInstance&, Mob*, Player*) const;
    virtual void mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
    virtual std::string buildDescriptionName(ItemInstance const&) const;
    virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
    virtual void readUserData(ItemInstance&, IDataInput&) const;
    virtual void writeUserData(ItemInstance const&, IDataOutput&) const;
    virtual int getMaxStackSize(ItemInstance const&) const;
    virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool) const;
    virtual void onCraftedBy(ItemInstance&, Level&, Player&) const;
    virtual CooldownType getCooldownType() const;
    virtual int getCooldownTime() const;
    virtual std::string getInteractText(Player const&) const;
    virtual int getAnimationFrameFor(Mob&) const;
    virtual bool isEmissive(int) const;
    virtual TextureUVCoordinateSet const& getIcon(int, int, bool) const;
    virtual int getIconYOffset() const;
    virtual bool isMirroredArt() const;
    virtual bool _checkUseOnPermissions(Entity&, ItemInstance&, signed char const&, BlockPos const&) const;
    virtual void _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
    virtual void _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;
public:
    static void initClientData();
    static void initCreativeItems();
    static void addCreativeItem(ItemInstance const&);
    static Item* lookupByName(std::string const&, bool);
    static void addBlockItems();
    static void registerItems();
    static void teardownItems();
    static std::shared_ptr<TextureAtlas> getTextureItem(std::string const&);
    static void initServerData(ResourcePackManager&);
    static void addCreativeItem(Block const*, short);
    static void addCreativeItem(Item*, short);
    static void addCreativeItem(short, short);
    static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);
public:
    void setTextureAtlas(std::shared_ptr<TextureAtlas>);
    void _textMatch(std::string const&, std::string const&, bool);
    void initClient(Json::Value&, Json::Value&);
    void initServer(Json::Value&);
    void setAllowOffhand(bool);
    void setIsMirroredArt(bool);
    void allowOffhand() const;
    void destroySpeedBonus(ItemInstance const&) const;
    void updateCustomBlockEntityTag(BlockSource&, ItemInstance&, BlockPos&) const;
    void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float) const;
public:
	static Item* mItems[512];
	static std::unordered_map<std::string,std::pair<std::string const,std::unique_ptr<Item> > > mItemLookupMap;
	static Item* mItemTextureAtlas;
	static Item* ICON_DESCRIPTION_PREFIX;
	static Item* mRandom;
public:
    static Item* mSword_wood;
    static Item* mShovel_wood;
    static Item* mHatchet_wood;
    static Item* mApple;
    static Item* mString;
    static Item* mDye_powder;
    static Item* mSword_iron;
    static Item* mSeeds_wheat;
    static Item* mCreativeList;
    static Item* mChestplate_iron;
    static Item* mFilledMap;
    static Item* mArrow;
    static Item* mDiamond;
    static Item* mSlimeBall;
    static Item* mCarrot;
    static Item* mSnowBall;
    static Item* mMobPlacer;
    static Item* mBoots_iron;
    static Item* mEndCrystal;
    static Item* mFishingRod;
    static Item* mHelmet_iron;
    static Item* mTNTMinecart;
    static Item* mChestMinecart;
    static Item* mLeggings_iron;
    static Item* mHopperMinecart;
    static Item* mCommandBlockMinecart;
    static Item* mBow;
    static Item* mBoat;
    static Item* mSign;
    static Item* mSkull;
    static Item* mMinecart;
    static Item* mPainting;
    static Item* mEnderpearl;
    static Item* mSplash_potion;
    static Item* mLingering_potion;
    static Item* mExperiencePotionItem;
    static Item* mEgg;
    static Item* mEnderEye;
    static Item* mEmerald;
    static Item* mCarrotOnAStick;
    static Item* mClock;
    static Item* mCompass;
    static Item* mGlass_bottle;
    static Item* mPaper;
    static Item* mGoldIngot;
    static Item* mIronIngot;
    static Item* mBeef_cooked;
    static Item* mGold_nugget;
    static Item* mIron_nugget;
    static Item* mNetherbrick;
    static Item* mPotatoBaked;
    static Item* mNetherQuartz;
    static Item* mRabbitCooked;
    static Item* mMutton_cooked;
    static Item* mChicken_cooked;
    static Item* mFish_cooked_cod;
    static Item* mFish_cooked_salmon;
    static Item* mCoal;
    static Item* mBrick;
    static Item* mRedStone;
    static Item* mLead;
    static Item* mBread;
    static Item* mWheat;
    static Item* mPotato;
    static Item* mGoldHorseArmor;
    static Item* mIronHorseArmor;
    static Item* mDiamondHorseArmor;
    static Item* mLeatherHorseArmor;
    static Item* mSaddle;
    static Item* mFish_raw_cod;
    static Item* mRotten_flesh;
    static Item* mFish_raw_salmon;
    static Item* mLeggings_leather;
    static Item* mFish_raw_clownfish;
    static Item* mFish_raw_pufferfish;
    static Item* mBone;
    static Item* mBook;
    static Item* mBowl;
    static Item* mStick;
    static Item* mPotion;
    static Item* mLeather;
    static Item* mNameTag;
    static Item* mHopper;
    static Item* mEnchanted_book;
    static Item* mHelmet_leather;
    static Item* mTotem;
    static Item* mSeeds_beetroot;
    static Item* mBeetroot;
    static Item* mGenerateDenyParticleEffect;
    static Item* mGhast_tear;
    static Item* mRabbitFoot;
    static Item* mSpider_eye;
    static Item* mYellowDust;
    static Item* mBlazePowder;
    static Item* mMagma_cream;
    static Item* mNether_wart;
    static Item* mGoldenCarrot;
    static Item* mDragon_breath;
    static Item* mSpeckled_melon;
    static Item* mFermented_spider_eye;
    static Item* mSugar;
    static Item* mSulphur;
    static Item* mBoots_gold;
    static Item* mBoots_chain;
    static Item* mHelmet_gold;
    static Item* mHelmet_chain;
    static Item* mBoots_diamond;
    static Item* mBoots_leather;
    static Item* mLeggings_gold;
    static Item* mHelmet_diamond;
    static Item* mLeggings_chain;
    static Item* mChestplate_gold;
    static Item* mChestplate_chain;
    static Item* mLeggings_diamond;
    static Item* mChestplate_diamond;
    static Item* mChestplate_leather;
    static Item* mElytra;
    static Item* mRabbitRaw;
    static Item* mMutton_raw;
    static Item* mSword_gold;
    static Item* mChicken_raw;
    static Item* mChorusFruit;
    static Item* mShovel_gold;
    static Item* mShovel_iron;
    static Item* mHatchet_gold;
    static Item* mHatchet_iron;
    static Item* mPickAxe_gold;
    static Item* mPickAxe_iron;
    static Item* mPorkChop_raw;
    static Item* mPorkChop_cooked;
    static Item* mChorusFruitPopped;
    static Item* mClay;
    static Item* mBeef_raw;
    static Item* mHoe_gold;
    static Item* mHoe_iron;
    static Item* mEmptyMap;
    static Item* mDoor_iron;
    static Item* mDoor_wood;
    static Item* mFlowerPot;
    static Item* mItemFrame;
    static Item* mApple_gold;
    static Item* mComparator;
    static Item* mDoor_birch;
    static Item* mFireCharge;
    static Item* mMelonSlice;
    static Item* mRabbitHide;
    static Item* mRabbitStew;
    static Item* mDoor_acacia;
    static Item* mDoor_jungle;
    static Item* mDoor_spruce;
    static Item* mDoor_darkoak;
    static Item* mBrewing_stand;
    static Item* mFlintAndSteel;
    static Item* mApple_enchanted;
    static Item* mPrismarineShard;
    static Item* mPrismarineCrystals;
    static Item* mBed;
    static Item* mCake;
    static Item* mFlint;
    static Item* mReeds;
    static Item* mBucket;
    static Item* mBlazeRod;
    static Item* mCauldron;
    static Item* mRepeater;
    static Item* mNetherStar;
    static Item* mShulkerShell;
    static Item* mHoe_stone;
    static Item* mHoe_diamond;
    static Item* mPickAxe_wood;
    static Item* mShovel_stone;
    static Item* mHatchet_stone;
    static Item* mPickAxe_stone;
    static Item* mShovel_diamond;
    static Item* mHatchet_diamond;
    static Item* mPickAxe_diamond;
    static Item* mShears;
    static Item* mHoe_wood;
    static Item* mSword_stone;
    static Item* mSword_diamond;
    static Item* mFeather;
    static Item* mChalkboard;
    static Item* mPumpkinPie;
    static Item* mSeeds_melon;
    static Item* mBeetrootSoup;
    static Item* mMushroomStew;
    static Item* mPortfolioBook;
    static Item* mSeeds_pumpkin;
    static Item* mPoisonous_potat;
    static Item* mCamera;
    static Item* mCookie;
};