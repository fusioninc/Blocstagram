//
//  DataSource.h
//  Blocstagram
//
//  Created by Fusion on 7/5/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DataSource : NSObject

+ (instancetype) sharedInstance;

@property (nonatomic, strong, readonly) NSArray *mediaItems;


@end
