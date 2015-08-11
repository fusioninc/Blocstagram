//
//  Media.h
//  Blocstagram
//
//  Created by Fusion on 7/5/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LikeButton.h"

typedef NS_ENUM(NSInteger, MediaDownloadState) {
    MediaDownloadStateNeedsImage             = 0,
    MediaDownloadStateDownloadInProgress     = 1,
    MediaDownloadStateNonRecoverableError    = 2,
    MediaDownloadStateHasImage               = 3
};

@class User;

@interface Media : NSObject <NSCoding>

@property (nonatomic, copy) NSString *idNumber;
@property (nonatomic, strong) User *user;
@property (nonatomic, strong) NSURL *mediaURL;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) MediaDownloadState downloadState;

@property (nonatomic, copy) NSString *caption;
@property (nonatomic, copy) NSArray *comments;

@property (nonatomic, assign) LikeState likeState;
@property (nonatomic, strong) NSString *temporaryComment;
@property (nonatomic, strong) NSNumber *numberOfLikes; //NSUInteger

- (instancetype) initWithDictionary:(NSDictionary *)mediaDictionary;

@end
