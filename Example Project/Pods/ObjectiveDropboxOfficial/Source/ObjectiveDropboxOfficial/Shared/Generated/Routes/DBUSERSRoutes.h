///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBTasks.h"

@class DBNilObject;
@class DBUSERSAccountType;
@class DBUSERSBasicAccount;
@class DBUSERSFullAccount;
@class DBUSERSFullTeam;
@class DBUSERSGetAccountBatchError;
@class DBUSERSGetAccountError;
@class DBUSERSName;
@class DBUSERSSpaceAllocation;
@class DBUSERSSpaceUsage;

@protocol DBTransportClient;

///
/// Routes for the `Users` namespace
///
@interface DBUSERSRoutes : NSObject

/// An instance of the networking client that each route will use to submit a
/// request.
@property (nonatomic, readonly) id<DBTransportClient> _Nonnull client;

/// Initializes the `DBUSERSRoutes` namespace container object with a networking
/// client.
- (nonnull instancetype)init:(id<DBTransportClient> _Nonnull)client;

///
/// Get information about a user's account.
///
/// @param accountId A user's account identifier.
///
/// @return Through the response callback, the caller will receive a `DBUSERSBasicAccount` object on success or a
/// `DBUSERSGetAccountError` object on failure.
///
- (DBRpcTask<DBUSERSBasicAccount *, DBUSERSGetAccountError *> * _Nonnull)getAccount:(NSString * _Nonnull)accountId;

///
/// Get information about multiple user accounts.  At most 300 accounts may be queried per request.
///
/// @param accountIds List of user account identifiers.  Should not contain any duplicate account IDs.
///
/// @return Through the response callback, the caller will receive a `NSArray<DBUSERSBasicAccount *>` object on success
/// or a `DBUSERSGetAccountBatchError` object on failure.
///
- (DBRpcTask<NSArray<DBUSERSBasicAccount *> *, DBUSERSGetAccountBatchError *> * _Nonnull)getAccountBatch:
    (NSArray<NSString *> * _Nonnull)accountIds;

///
/// Get information about the current user's account.
///
///
/// @return Through the response callback, the caller will receive a `DBUSERSFullAccount` object on success or a `void`
/// object on failure.
///
- (DBRpcTask<DBUSERSFullAccount *, DBNilObject *> * _Nonnull)getCurrentAccount;

///
/// Get the space usage information for the current user's account.
///
///
/// @return Through the response callback, the caller will receive a `DBUSERSSpaceUsage` object on success or a `void`
/// object on failure.
///
- (DBRpcTask<DBUSERSSpaceUsage *, DBNilObject *> * _Nonnull)getSpaceUsage;

@end
