module MakeUpper (makeUpperCase) where
import Data.Char (toUpper)

makeUpperCase :: String -> String
makeUpperCase = map toUpper