#![allow(unused_parens)]
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]

mod bvm;

use wasm_bindgen::prelude::*;

use bvm::root::*;
use bvm::root::Env::*;
use std::mem::size_of;
use std::os::raw::c_void;
use wasm_bindgen::prelude::*;

pub const s_SID: ShaderID = [0xe3,0x21,0x90,0x44,0x42,0x00,0x0f,0xfd,0x2d,0x2f,0xf0,0x46,0x3f,0x8a,0x77,0x21,0x1b,0x82,0xe4,0x61,0xd3,0x97,0xe1,0xb2,0x20,0x8c,0xc9,0x3b,0xb6,0xa1,0x04,0x65];

#[wasm_bindgen]
pub struct Params {
    s_iMethod: u32, //0

    m_BacklogPeriod: Height,
    m_MaxWithdraw: Amount
}

#[wasm_bindgen]
pub struct Deposit {
    s_iMethod: u32, //2

    m_Aid: AssetID,
    m_Amount: Amount
}

#[wasm_bindgen]
pub struct Key {
    m_Account: PubKey,
    m_Aid: AssetID
}

#[wasm_bindgen]
pub struct Withdraw {
    s_iMethod: u32, //3

    m_Key: Key,
    m_Amount: Amount
}

#[wasm_bindgen]
pub struct AccountData {
    m_h0: Height,
    m_Amount: Amount
}

#[wasm_bindgen]
pub fn Ctor(r: Params)
{
    let mut parameters = r;
    let param_ptr: *mut c_void = &mut parameters as *mut _ as *mut c_void;
    unsafe
    {
        SaveVar(0 as *const c_void, size_of::<u8>() as u32, param_ptr, size_of::<Params>() as u32, KeyTag_Internal);
    }
}

#[wasm_bindgen]
pub fn Dtor()
{
    unsafe
    {
        SaveVar(0 as *const c_void, size_of::<u8>() as u32, 0 as *mut c_void, size_of::<Params>() as u32, KeyTag_Internal);
    }
}

#[wasm_bindgen]
pub fn Method_2(r: Deposit)
{
    unsafe
    {
        FundsLock(r.m_Aid, r.m_Amount);
    }
}

#[wasm_bindgen]
pub fn Method_3(r: Withdraw)
{
    unsafe
    {
        let h: Height = get_Height();
    }
    //let pars: Params;
    //LoadVar(0 as *const c_void, size_of::<u8>(), pars, size_of::<Params>());

    // let ad: AccountData;
    // let bLoaded: bool = LoadVar(r.m_Key as *const c_void, size_of::<u8>(), ad, size_of::<AccountData>());
    // let bEmpty: bool = !bLoaded || (h - ad.m_h0 >= pars.m_BacklogPeriod);

    // if (r.m_Amount)
    // {
    //     if (bEmpty)
    //     {
    //         ad.m_h0 = h;
    //         ad.m_Amount = r.m_Amount;
    //     }
    //     else
    //     {
    //         ad.m_Amount += r.m_Amount;
    //         if (ad.m_Amount < r.m_Amount)
    //         {
    //             Halt();
    //         }
    //     }

    //     if (ad.m_Amount > pars.m_MaxWithdraw)
    //     {
    //         Halt();
    //     }
    //     SaveVar(r.m_Key as *const c_void, size_of::<u8>(), ad, size_of::<AccountData>());

    //     FundsUnlock(r.m_Key.m_Aid, r.m_Amount); // would fail if not enough funds in the contract
    // }
    // else
    // {
    //     if (bLoaded && bEmpty)
    //     {
    //         SaveVar(r.m_Key as *const c_void, size_of::<u8>(), 0, size_of::<AccountData>());
    //     }
    // }

    // AddSig(r.m_Key.m_Account);
}
