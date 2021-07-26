
#include "common.hpp"

#pragma once

namespace Env 
{
    // Common functions
    void* Memcpy(void* pDst , const void* pSrc , uint32_t size);
    void* Memset(void* pDst , uint8_t val , uint32_t size);
    int32_t Memcmp(const void* p1 , const void* p2 , uint32_t size);
    uint8_t Memis0(const void* p , uint32_t size);
    uint32_t Strlen(const char* sz);
    int32_t Strcmp(const char* sz1 , const char* sz2);
    void* StackAlloc(uint32_t size);
    void StackFree(uint32_t size);
    void* Heap_Alloc(uint32_t size);
    void Heap_Free(void* pPtr);
    void Halt();
    void HashWrite(HashObj* pHash , const void* p , uint32_t size);
    void HashGetValue(HashObj* pHash , void* pDst , uint32_t size);
    void HashFree(HashObj* pHash);
    Height get_Height();
    void get_HdrInfo(BlockHeader::Info& hdr);
    void get_HdrFull(BlockHeader::Full& hdr);
    Height get_RulesCfg(Height h , HashValue& res);
    HashObj* HashCreateSha256();
    HashObj* HashCreateBlake2b(const void* pPersonal , uint32_t nPersonal , uint32_t nResultSize);
    HashObj* HashCreateKeccak(uint32_t nBits);
    Secp_scalar* Secp_Scalar_alloc();
    void Secp_Scalar_free(Secp_scalar& s);
    uint8_t Secp_Scalar_import(Secp_scalar& s , const Secp_scalar_data& data);
    void Secp_Scalar_export(const Secp_scalar& s , Secp_scalar_data& data);
    void Secp_Scalar_neg(Secp_scalar& dst , const Secp_scalar& src);
    void Secp_Scalar_add(Secp_scalar& dst , const Secp_scalar& a , const Secp_scalar& b);
    void Secp_Scalar_mul(Secp_scalar& dst , const Secp_scalar& a , const Secp_scalar& b);
    void Secp_Scalar_inv(Secp_scalar& dst , const Secp_scalar& src);
    void Secp_Scalar_set(Secp_scalar& dst , uint64_t val);
    Secp_point* Secp_Point_alloc();
    void Secp_Point_free(Secp_point& p);
    uint8_t Secp_Point_Import(Secp_point& p , const PubKey& pk);
    void Secp_Point_Export(const Secp_point& p , PubKey& pk);
    void Secp_Point_neg(Secp_point& dst , const Secp_point& src);
    void Secp_Point_add(Secp_point& dst , const Secp_point& a , const Secp_point& b);
    void Secp_Point_mul(Secp_point& dst , const Secp_point& p , const Secp_scalar& s);
    uint8_t Secp_Point_IsZero(const Secp_point& p);
    void Secp_Point_mul_G(Secp_point& dst , const Secp_scalar& s);
    void Secp_Point_mul_J(Secp_point& dst , const Secp_scalar& s);
    void Secp_Point_mul_H(Secp_point& dst , const Secp_scalar& s , AssetID aid);
    uint8_t VerifyBeamHashIII(const void* pInp , uint32_t nInp , const void* pNonce , uint32_t nNonce , const void* pSol , uint32_t nSol);

    // Contract only functions
    uint32_t LoadVar(const void* pKey , uint32_t nKey , void* pVal , uint32_t nVal , uint8_t nType);
    uint32_t SaveVar(const void* pKey , uint32_t nKey , const void* pVal , uint32_t nVal , uint8_t nType);
    uint32_t EmitLog(const void* pKey , uint32_t nKey , const void* pVal , uint32_t nVal , uint8_t nType);
    void CallFar(const ContractID& cid , uint32_t iMethod , void* pArgs , uint32_t nArgs , uint8_t bInheritContext);
    uint32_t get_CallDepth();
    void get_CallerCid(uint32_t iCaller , ContractID& cid);
    void AddSig(const PubKey& pubKey);
    void FundsLock(AssetID aid , Amount amount);
    void FundsUnlock(AssetID aid , Amount amount);
    uint8_t RefAdd(const ContractID& cid);
    uint8_t RefRelease(const ContractID& cid);
    AssetID AssetCreate(const void* pMeta , uint32_t nMeta);
    uint8_t AssetEmit(AssetID aid , Amount amount , uint8_t bEmit);
    uint8_t AssetDestroy(AssetID aid);

    // Application-only functions
    uint32_t Vars_Enum(const void* pKey0 , uint32_t nKey0 , const void* pKey1 , uint32_t nKey1);
    uint8_t Vars_MoveNext(uint32_t iSlot , void* pKey , uint32_t& nKey , void* pVal , uint32_t& nVal , uint8_t nRepeat);
    void Vars_Close(uint32_t iSlot);
    uint32_t VarGetProof(const void* pKey , uint32_t nKey , const void** ppVal , uint32_t* pnVal , const Merkle::Node** ppProof);
    uint32_t Logs_Enum(const void* pKey0 , uint32_t nKey0 , const void* pKey1 , uint32_t nKey1 , const HeightPos* pPosMin , const HeightPos* pPosMax);
    uint8_t Logs_MoveNext(uint32_t iSlot , void* pKey , uint32_t& nKey , void* pVal , uint32_t& nVal , HeightPos& pos , uint8_t nRepeat);
    void Logs_Close(uint32_t iSlot);
    uint32_t LogGetProof(const HeightPos& pos , const Merkle::Node** ppProof);
    void DerivePk(PubKey& pubKey , const void* pID , uint32_t nID);
    void DocAddGroup(const char* szID);
    void DocCloseGroup();
    void DocAddText(const char* szID , const char* val);
    void DocAddNum32(const char* szID , uint32_t val);
    void DocAddNum64(const char* szID , uint64_t val);
    void DocAddArray(const char* szID);
    void DocCloseArray();
    void DocAddBlob(const char* szID , const void* pBlob , uint32_t nBlob);
    uint32_t DocGetText(const char* szID , char* szRes , uint32_t nLen);
    uint8_t DocGetNum32(const char* szID , uint32_t* pOut);
    uint8_t DocGetNum64(const char* szID , uint64_t* pOut);
    uint32_t DocGetBlob(const char* szID , void* pOut , uint32_t nLen);
    void GenerateKernel(const ContractID* pCid , uint32_t iMethod , const void* pArg , uint32_t nArg , const FundsChange* pFunds , uint32_t nFunds , const SigRequest* pSig , uint32_t nSig , const char* szComment , uint32_t nCharge);
}

