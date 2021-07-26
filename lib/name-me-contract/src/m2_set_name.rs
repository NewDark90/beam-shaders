use crate::contract_vars;
use wasm_bindgen::prelude::*;
use bvm::root::*;
use ::std::{
    mem::size_of,
    os::raw::{
        c_char,
        c_void
    }
};

#[wasm_bindgen]
pub struct NameParams {
    pub name: *const c_char
}

#[wasm_bindgen]
pub struct NameMe {
    pub name: *const c_char,
    pub attr: u8
}

pub(crate) fn SetName(params: NameParams)
{
    unsafe
    {
        let mut name_me = NameMe {
            attr: (Env::get_Height() % 8) as u8,
            name: params.name
        };
        let name_me_ptr = &mut name_me as *mut _ as *mut c_void;

        Env::SaveVar(
            contract_vars::name as *const c_void, 
            size_of::<u8>() as u32, 
            name_me_ptr, 
            size_of::<NameMe>() as u32, 
            KeyTag_Internal
        );
    }
}

#[wasm_bindgen]
pub fn Method_2(params: NameParams) { return SetName(params); }