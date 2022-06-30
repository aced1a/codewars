module FirstNonConsecutive (firstNonConsecutive) where
import Data.List (find)


diff :: (Num a) => [a] -> [a]
diff fs = zipWith (-) fs (tail fs)

get :: Maybe (b, b) -> Maybe b
get = fmap fst

firstNonConsecutive :: (Eq b, Num b) => [b] -> Maybe b
firstNonConsecutive xs = get result
              where result = find (\x -> snd x /= -1) (zip (tail xs) (diff xs))