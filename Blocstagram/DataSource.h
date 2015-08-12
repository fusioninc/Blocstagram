//
//  DataSource.h
//  Blocstagram
//
//  Created by Fusion on 7/5/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <Foundation/Foundation.h>


@class Media;

typedef void (^NewItemCompletionBlock)(NSError *error);

@interface DataSource : NSObject

+ (instancetype) sharedInstance;

@property (nonatomic, strong, readonly) NSArray *mediaItems;
@property (nonatomic, strong, readonly) NSString *accessToken;

- (void) deleteMediaItem:(Media *)item;
- (void) addMediaItem:(Media *)item;
- (void) requstNewItemsWithCompletionHandler:(NewItemCompletionBlock)completionHandler;
- (void) requstOldItemWithCompletionHandler:(NewItemCompletionBlock)completionHandler;
- (void) downloadImageForMediaItem:(Media *)mediaItem;
- (void) toggleLikeOnMediaItem:(Media *)mediaItem withCompletionHandler:(void (^)(void))completionHandler;
- (void) commentOnMediaItem:(Media *)mediaItem withCommentText:(NSString *)commentText;

+ (NSString *) instagramClientID;

@end
