module Game where
--------------------------------------------------------------------------------
data Item = Sword
            | Bow
            | MagicWand deriving Eq
--------------------------------------------------------------------------------
data Mob = Mummy
            | Skeleton Item
            | Witch (Maybe Item) deriving Eq
--------------------------------------------------------------------------------
instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"
--------------------------------------------------------------------------------
createMummy :: Mob
createMummy = Mummy
--------------------------------------------------------------------------------
createArcher :: Mob
createArcher = Skeleton Bow
--------------------------------------------------------------------------------
createKnight :: Mob
createKnight = Skeleton Sword
--------------------------------------------------------------------------------
createWitch :: Mob
createWitch = Witch Nothing
--------------------------------------------------------------------------------
createSorceress :: Mob
createSorceress = Witch (Just MagicWand)
--------------------------------------------------------------------------------
create :: String -> Maybe Mob
create a = case a of
    "mummy" -> Just createMummy
    "doomed archer" -> Just createArcher
    "dead knight" -> Just createKnight
    "witch" -> Just createWitch
    "sorceress" -> Just createSorceress
    otherwise -> Nothing
--------------------------------------------------------------------------------
equip :: Item -> Mob -> Maybe Mob
equip a Mummy = Nothing
equip a (Skeleton b) = Just (Skeleton a)
equip a (Witch b) = Just (Witch (Just a))
--------------------------------------------------------------------------------
instance Show Mob where
    show (Mummy) = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton MagicWand) = "skeleton holding a magic wand"
    show (Witch Nothing) = "witch"
    show (Witch (Just Bow)) = "witch holding a bow"
    show (Witch (Just Sword)) = "witch holding a sword"
    show (Witch (Just MagicWand)) = "sorceress"
--------------------------------------------------------------------------------
class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem a = if (getItem a == Nothing) then False else True
--------------------------------------------------------------------------------
instance HasItem Mob where
    getItem (Skeleton a) = Just a
    getItem (Witch a) = a
    getItem Mummy = Nothing