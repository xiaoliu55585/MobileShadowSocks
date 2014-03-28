//
//  ProfileManager.h
//  MobileShadowSocks
//
//  Created by Linus Yang on 14-3-12.
//  Copyright (c) 2014 Linus Yang. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kProfileCurrentSelected @"SELECTED_PROFILE"
#define kProfileList @"PROFILE_LIST"
#define kProfileProxyEnabled @"PROXY_ENABLED"
#define kProfileVPNMode @"VPN_MODE"
#define kProfileAppProxy @"APP_PROXY"
#define kProfileLastBootTime @"LAST_BOOT_TIME"

#define kProfileDefaultName NSLocalizedString(@"Default", nil)
#define kProfileDefaultIndex -1
#define kProfileName @"PROFILE_NAME"

#define kProfileServer @"REMOTE_SERVER"
#define kProfilePort @"REMOTE_PORT"
#define kProfilePass @"SOCKS_PASS"
#define kProfileCrypto @"CRYPTO_METHOD"
#define kProfilePac @"PAC_FILE"
#define kProfileExcept @"EXCEPTION_LIST"
#define kProfileAutoProxy @"AUTO_PROXY"

@interface ProfileManager : NSObject

@property (nonatomic, retain, readonly) NSString *configPath;

+ (ProfileManager *)sharedProfileManager;

- (BOOL)syncSettings;
- (void)removeConfigFile;
- (BOOL)configFileExists;

- (NSInteger)currentProfile;
- (NSInteger)profileListCount;
- (NSString *)nameOfProfile:(NSInteger)index;
- (NSString *)nameOfCurrentProfile;

- (void)selectProfile:(NSInteger)profileIndex;
- (void)removeProfile:(NSInteger)profileIndex;
- (void)reorderProfile:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;
- (void)renameProfile:(NSInteger)index withName:(NSString *)name;
- (void)reloadProfile;
- (void)createProfile:(NSString *)profileName withInfo:(NSDictionary *)rawInfo;

- (void)saveObject:(id)value forKey:(NSString *)key;
- (id)readObject:(NSString *)key;
- (void)saveBool:(BOOL)value forKey:(NSString *)key;
- (BOOL)readBool:(NSString *)key;
- (void)saveInt:(NSInteger)value forKey:(NSString *)key;
- (NSInteger)readInt:(NSString *)key;
- (NSString *)fetchConfigForKey:(NSString *)key andDefault:(NSString *)defaultValue;

@end
