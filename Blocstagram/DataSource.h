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

- (void) deleteMediaItem:(Media *)item;
- (void) addMediaItem:(Media *)item;
- (void) requstNewItemsWithCompletionHandler:(NewItemCompletionBlock)completionHandler;
- (void) requstOldItemWithCompletionHandler:(NewItemCompletionBlock)completionHandler;

@end
