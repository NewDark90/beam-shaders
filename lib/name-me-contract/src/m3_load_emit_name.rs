use crate::contract_vars;
use crate::m2_set_name::{
    NameMe
};
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
pub struct NameMeEmit {
    pub name: *const c_char,
    pub attr: u8,
    pub desc: *const c_char
}

pub(crate) fn load_emit_log()
{
    unsafe
    {
        let mut name_me = NameMe {
            name: 0 as *const c_char,
            attr: 0
        };
        let name_me_ptr = &mut name_me as *mut _ as *mut c_void;

        //Not sure if loading is necessary, but we're doing it anyway!
        Env::LoadVar(
            contract_vars::name as *const c_void, 
            size_of::<u8>() as u32, 
            name_me_ptr, 
            size_of::<NameMe>() as u32, 
            KeyTag_Internal
        );

        Env::EmitLog(
            contract_vars::name as *const c_void, 
            size_of::<u8>() as u32, 
            name_me_ptr, 
            size_of::<NameMe>() as u32, 
            KeyTag_Internal
        );
    }
}


#[wasm_bindgen]
pub fn Method_3() { return load_emit_log(); }