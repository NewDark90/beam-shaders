use crate::ctor::Params;

use wasm_bindgen::prelude::*;
use bvm::root::*;
use bvm::root::Env::*;
use std::mem::size_of;
use std::os::raw::c_void;

#[wasm_bindgen]
pub fn Dtor()
{
    unsafe
    {
        SaveVar(
            0 as *const c_void, 
            size_of::<u8>() as u32, 
            0 as *mut c_void, 
            size_of::<Params>() as u32, 
            KeyTag_Internal
        );
    }
}