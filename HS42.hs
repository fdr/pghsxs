{-# LANGUAGE ForeignFunctionInterface #-}
module HS42 where
import Foreign.C.Types
import Data.Word

foreign export ccall "hs42" hs42 :: Word16

hs42                        ::  Word16
hs42                         =  42

