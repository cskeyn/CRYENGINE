// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "FileIOHandler.h"
#include "ATLEntities.h"

#if (CRY_PLATFORM_WINDOWS && CRY_PLATFORM_64BIT) && !defined(IS_EAAS)
	#define WWISE_USE_OCULUS
#endif // (CRY_PLATFORM_WINDOWS && CRY_PLATFORM_64BIT) && !defined(IS_EAAS)

namespace CryAudio
{
namespace Impl
{
namespace Wwise
{
class CAudioImpl final : public IAudioImpl
{
public:

	CAudioImpl();
	virtual ~CAudioImpl() override = default;
	CAudioImpl(CAudioImpl const&) = delete;
	CAudioImpl(CAudioImpl&&) = delete;
	CAudioImpl& operator=(CAudioImpl const&) = delete;
	CAudioImpl& operator=(CAudioImpl&&) = delete;

	// IAudioImpl
	virtual void                     Update(float const deltaTime) override;

	virtual EAudioRequestStatus      Init() override;
	virtual EAudioRequestStatus      ShutDown() override;
	virtual EAudioRequestStatus      Release() override;
	virtual EAudioRequestStatus      OnLoseFocus() override;
	virtual EAudioRequestStatus      OnGetFocus() override;
	virtual EAudioRequestStatus      MuteAll() override;
	virtual EAudioRequestStatus      UnmuteAll() override;
	virtual EAudioRequestStatus      StopAllSounds() override;
	virtual EAudioRequestStatus      RegisterAudioObject(IAudioObject* const pAudioObject, char const* const szAudioObjectName) override;
	virtual EAudioRequestStatus      RegisterAudioObject(IAudioObject* const pAudioObject) override;
	virtual EAudioRequestStatus      UnregisterAudioObject(IAudioObject* const pAudioObject) override;
	virtual EAudioRequestStatus      ResetAudioObject(IAudioObject* const pAudioObject) override;
	virtual EAudioRequestStatus      UpdateAudioObject(IAudioObject* const pAudioObject) override;
	virtual EAudioRequestStatus      PlayFile(SAudioStandaloneFileInfo* const _pAudioStandaloneFileInfo) override;
	virtual EAudioRequestStatus      StopFile(SAudioStandaloneFileInfo* const _pAudioStandaloneFileInfo) override;
	virtual EAudioRequestStatus      PrepareTriggerSync(IAudioObject* const pAudioObject, IAudioTrigger const* const pAudioTrigger) override;
	virtual EAudioRequestStatus      UnprepareTriggerSync(IAudioObject* const pAudioObject, IAudioTrigger const* const pAudioTrigger) override;
	virtual EAudioRequestStatus      PrepareTriggerAsync(IAudioObject* const pAudioObject, IAudioTrigger const* const pAudioTrigger, IAudioEvent* const pAudioEvent) override;
	virtual EAudioRequestStatus      UnprepareTriggerAsync(IAudioObject* const pAudioObject, IAudioTrigger const* const pAudioTrigger, IAudioEvent* const pAudioEvent) override;
	virtual EAudioRequestStatus      ActivateTrigger(IAudioObject* const pAudioObject, IAudioTrigger const* const pAudioTrigger, IAudioEvent* const pAudioEvent) override;
	virtual EAudioRequestStatus      StopEvent(IAudioObject* const pAudioObject, IAudioEvent const* const pAudioEvent) override;
	virtual EAudioRequestStatus      StopAllEvents(IAudioObject* const _pAudioObject) override;
	virtual EAudioRequestStatus      Set3DAttributes(IAudioObject* const pAudioObject, SAudioObject3DAttributes const& attributes) override;
	virtual EAudioRequestStatus      SetEnvironment(IAudioObject* const pAudioObject, IAudioEnvironment const* const pAudioEnvironment, float const amount) override;
	virtual EAudioRequestStatus      SetRtpc(IAudioObject* const pAudioObject, IAudioRtpc const* const pAudioRtpc, float const value) override;
	virtual EAudioRequestStatus      SetSwitchState(IAudioObject* const pAudioObject, IAudioSwitchState const* const pAudioSwitchState) override;
	virtual EAudioRequestStatus      SetObstructionOcclusion(IAudioObject* const pAudioObject, float const obstruction, float const occlusion) override;
	virtual EAudioRequestStatus      SetListener3DAttributes(IAudioListener* const pAudioListener, SAudioObject3DAttributes const& attributes) override;
	virtual EAudioRequestStatus      RegisterInMemoryFile(SAudioFileEntryInfo* const pAudioFileEntry) override;
	virtual EAudioRequestStatus      UnregisterInMemoryFile(SAudioFileEntryInfo* const pAudioFileEntry) override;
	virtual EAudioRequestStatus      ParseAudioFileEntry(XmlNodeRef const pAudioFileEntryNode, SAudioFileEntryInfo* const pFileEntryInfo) override;
	virtual void                     DeleteAudioFileEntry(IAudioFileEntry* const pOldAudioFileEntry) override;
	virtual char const* const        GetAudioFileLocation(SAudioFileEntryInfo* const pFileEntryInfo) override;
	virtual IAudioTrigger const*     NewAudioTrigger(XmlNodeRef const pAudioTriggerNode) override;
	virtual void                     DeleteAudioTrigger(IAudioTrigger const* const pOldAudioTrigger) override;
	virtual IAudioRtpc const*        NewAudioRtpc(XmlNodeRef const pAudioRtpcNode) override;
	virtual void                     DeleteAudioRtpc(IAudioRtpc const* const pOldAudioRtpc) override;
	virtual IAudioSwitchState const* NewAudioSwitchState(XmlNodeRef const pAudioSwitchStateImplNode) override;
	virtual void                     DeleteAudioSwitchState(IAudioSwitchState const* const pOldAudioSwitchState) override;
	virtual IAudioEnvironment const* NewAudioEnvironment(XmlNodeRef const pAudioEnvironmentNode) override;
	virtual void                     DeleteAudioEnvironment(IAudioEnvironment const* const pOldAudioEnvironment) override;
	virtual IAudioObject*            NewGlobalAudioObject() override;
	virtual IAudioObject*            NewAudioObject() override;
	virtual void                     DeleteAudioObject(IAudioObject const* const pOldAudioObject) override;
	virtual IAudioListener*          NewDefaultAudioListener() override;
	virtual IAudioListener*          NewAudioListener() override;
	virtual void                     DeleteAudioListener(IAudioListener* const pOldListenerData) override;
	virtual IAudioEvent*             NewAudioEvent(AudioEventId const audioEventID) override;
	virtual void                     DeleteAudioEvent(IAudioEvent const* const pOldAudioEvent) override;
	virtual void                     ResetAudioEvent(IAudioEvent* const pAudioEvent) override;
	virtual IAudioStandaloneFile*    NewAudioStandaloneFile() override;
	virtual void                     DeleteAudioStandaloneFile(IAudioStandaloneFile const* const _pOldAudioStandaloneFile) override;
	virtual void                     ResetAudioStandaloneFile(IAudioStandaloneFile* const _pAudioStandaloneFile) override;
	virtual void                     GamepadConnected(TAudioGamepadUniqueID const deviceUniqueID) override;
	virtual void                     GamepadDisconnected(TAudioGamepadUniqueID const deviceUniqueID) override;
	virtual void                     OnAudioSystemRefresh() override;
	virtual void                     SetLanguage(char const* const szLanguage) override;

	// Below data is only used when INCLUDE_WWISE_IMPL_PRODUCTION_CODE is defined!
	virtual char const* const GetImplementationNameString() const override;
	virtual void              GetMemoryInfo(SAudioImplMemoryInfo& memoryInfo) const override;
	virtual void              GetAudioFileData(char const* const szFilename, SAudioFileData& audioFileData) const override;
	// ~IAudioImpl

private:

	static char const* const s_szWwiseEventTag;
	static char const* const s_szWwiseRtpcTag;
	static char const* const s_szWwiseSwitchTag;
	static char const* const s_szWwiseStateTag;
	static char const* const s_szWwiseRtpcSwitchTag;
	static char const* const s_szWwiseFileTag;
	static char const* const s_szWwiseAuxBusTag;
	static char const* const s_szWwiseValueTag;
	static char const* const s_szWwiseNameAttribute;
	static char const* const s_szWwiseValueAttribute;
	static char const* const s_szWwiseMutiplierAttribute;
	static char const* const s_szWwiseShiftAttribute;
	static char const* const s_szWwiseLocalisedAttribute;

	struct SEnvPairCompare
	{
		bool operator()(std::pair<AkAuxBusID, float> const& pair1, std::pair<AkAuxBusID, float> const& pair2) const;
	};

	void                     LoadEventsMetadata();
	SAudioSwitchState const* ParseWwiseSwitchOrState(XmlNodeRef pNode, EWwiseSwitchType eType);
	SAudioSwitchState const* ParseWwiseRtpcSwitch(XmlNodeRef pNode);
	void                     ParseRtpcImpl(XmlNodeRef const pNode, AkRtpcID& rtpcId, float& multiplier, float& shift);
	EAudioRequestStatus      PrepUnprepTriggerSync(IAudioTrigger const* const pAudioTrigger, bool bPrepare);
	EAudioRequestStatus      PrepUnprepTriggerAsync(IAudioTrigger const* const pAudioTrigger, IAudioEvent* const pAudioEvent, bool bPrepare);
	EAudioRequestStatus      PostEnvironmentAmounts(IAudioObject* const pAudioObject);
	void                     SignalAuxAudioThread();
	void                     WaitForAuxAudioThread();

	AkGameObjectID                              m_dummyGameObjectId;
	AkBankID                                    m_initBankId;
	CFileIOHandler                              m_fileIOHandler;

	CryFixedStringT<MAX_AUDIO_FILE_PATH_LENGTH> m_regularSoundBankFolder;
	CryFixedStringT<MAX_AUDIO_FILE_PATH_LENGTH> m_localizedSoundBankFolder;

	typedef std::map<TAudioGamepadUniqueID, AkUInt8, std::less<TAudioGamepadUniqueID>, STLSoundAllocator<std::pair<TAudioGamepadUniqueID const, AkUInt8>>> AudioInputDevices;
	AudioInputDevices m_mapInputDevices;

#if !defined(WWISE_FOR_RELEASE)
	bool m_bCommSystemInitialized;
#endif  // !WWISE_FOR_RELEASE

#if defined(INCLUDE_WWISE_IMPL_PRODUCTION_CODE)
	CryFixedStringT<MAX_AUDIO_FILE_PATH_LENGTH> m_fullImplString;
#endif  // INCLUDE_WWISE_IMPL_PRODUCTION_CODE

#if defined(WWISE_USE_OCULUS)
	void* m_pOculusSpatializerLibrary;
#endif  // WWISE_USE_OCULUS
};
}
}
}
