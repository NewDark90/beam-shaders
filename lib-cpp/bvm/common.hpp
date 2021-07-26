
#pragma once

// Common ord types
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned long long uint64_t;

typedef signed char int8_t;
typedef signed int int32_t;
typedef signed short int16_t;
typedef signed long long int64_t;

typedef uint64_t Height;
typedef uint64_t Amount;
typedef uint32_t AssetID;
typedef uint64_t Timestamp;

template <uint32_t nBytes>
struct Opaque {
    uint8_t m_p[nBytes];
};

struct Secp_point_data {
    Opaque<32> X;
    uint8_t Y;
};

struct HeightPos
{
    Height m_Height;
    uint32_t m_Pos;
};

typedef Secp_point_data PubKey;
typedef Opaque<32> ContractID;
typedef Opaque<32> ShaderID;
typedef Opaque<32> HashValue;
typedef Opaque<64> HashValue512;
typedef Opaque<32> Secp_scalar_data;

struct FundsChange
    {
        Amount m_Amount;
        AssetID m_Aid;
        uint8_t m_Consume;

        template <bool bToShader>
        void Convert()
        {
            ConvertOrd<bToShader>(m_Amount);
            ConvertOrd<bToShader>(m_Aid);
            ConvertOrd<bToShader>(m_Consume);
        }
    };

    struct SigRequest
    {
        const void* m_pID;
        uint32_t m_nID;
    };

    struct HashObj;
    struct Secp_scalar;
    struct Secp_point;

    struct BlockHeader
    {
        struct InfoBase
        {
            Timestamp m_Timestamp;
            HashValue m_Kernels;
            HashValue m_Definition;

            template <bool bToShader>
            void Convert()
            {
                ConvertOrd<bToShader>(m_Timestamp);
            }
        };

        struct Info
            :public InfoBase
        {
            Height m_Height;
            HashValue m_Hash;

            template <bool bToShader>
            void Convert()
            {
                ConvertOrd<bToShader>(m_Height);
                InfoBase::Convert<bToShader>();
            }
        };

        struct Prefix
        {
            Height m_Height;
            HashValue m_Prev;
            HashValue m_ChainWork; // not hash, just same size

            template <bool bToShader>
            void Convert()
            {
                ConvertOrd<bToShader>(m_Height);
            }
        };

        struct Element
            :public InfoBase
        {
            struct PoW
            {
                uint8_t m_pIndices[104];
                uint8_t m_pNonce[8];
                uint32_t m_Difficulty;

            } m_PoW;

            template <bool bToShader>
            void Convert()
            {
                InfoBase::Convert<bToShader>();
                ConvertOrd<bToShader>(m_PoW.m_Difficulty);
            }
        };

        struct Full
            :public Prefix
            ,public Element
        {
            template <bool bToShader>
            void Convert()
            {
                Prefix::Convert<bToShader>();
                Element::Convert<bToShader>();
            }

            void get_Hash(HashValue& out, const HashValue* pRules) const;

            template <bool bUseEnv = true>
            bool IsValid(const HashValue* pRules) const;

        protected:
            void get_HashInternal(HashValue& out, bool bFull, const HashValue* pRules) const;
            bool TestDifficulty() const;
        };
    };


    struct KeyTag
    {
        static const uint8_t Internal = 0;
        static const uint8_t InternalStealth = 8;
        static const uint8_t LockedAmount = 1;
        static const uint8_t Refs = 2;
        static const uint8_t OwnedAsset = 3;

        // Synthetic tags, not really contract vars
        static const uint8_t SidCid = 16; // Key={00...00}tag{sid}{cid}, Value=BigEndian(createHeight)
    };

    namespace Merkle
    {
        struct Node
        {
            uint8_t m_OnRight;
            HashValue m_Value;
        };
    }