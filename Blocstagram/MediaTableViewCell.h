//
//  MediaTableViewCell.h
//  Blocstagram
//
//  Created by Fusion on 7/6/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Media;

@interface MediaTableViewCell : UITableViewCell

@property (nonatomic, strong) Media *mediaItem;

+ (CGFloat) heightForMediaItem:(Media *) mediaItem width:(CGFloat)width;

@end
