
// Protocol_1_13.h

/*
Declares the 1.13 protocol classes:
	- cProtocol_1_13
		- release 1.13 protocol (#393)
(others may be added later in the future for the 1.13 release series)
*/





#pragma once

#include "Protocol_1_12.h"





class cProtocol_1_13 :
	public cProtocol_1_12_2
{
	typedef cProtocol_1_12_2 super;

public:
	cProtocol_1_13(cClientHandle * a_Client, const AString &a_ServerAddress, UInt16 a_ServerPort, UInt32 a_State);

protected:

	virtual void HandlePacketStatusRequest(cByteBuffer & a_ByteBuffer) override;
	virtual UInt32 GetPacketId(eOutgoingPackets a_Packet) override;
	virtual bool HandlePacket(cByteBuffer & a_ByteBuffer, UInt32 a_PacketType) override;
	virtual void HandlePacketPluginMessage(cByteBuffer & a_ByteBuffer) override;
	virtual void SendStatistics(const cStatManager & a_Manager) override;
	virtual void SendChunkData(int a_ChunkX, int a_ChunkZ, cChunkDataSerializer & a_Serializer) override;
	virtual void WriteItem(cPacketizer & a_Pkt, const cItem & a_Item) override;
	virtual void SendSoundEffect(const AString & a_SoundName, double a_X, double a_Y, double a_Z, float a_Volume, float a_Pitch) override;
	virtual void SendBlockChange(int a_BlockX, int a_BlockY, int a_BlockZ, BLOCKTYPE a_BlockType, NIBBLETYPE a_BlockMeta) override;
	virtual void SendBlockChanges(int a_ChunkX, int a_ChunkZ, const sSetBlockVector & a_Changes) override;
	virtual bool ReadItem(cByteBuffer & a_ByteBuffer, cItem & a_Item, size_t a_KeepRemainingBytes) override;
	virtual void WriteEntityMetadata(cPacketizer & a_Pkt, const cEntity & a_Entity) override;
};