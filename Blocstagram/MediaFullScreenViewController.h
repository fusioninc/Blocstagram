//
//  MediaFullScreenViewController.h
//  Blocstagram
//
//  Created by Fusion on 7/27/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Media;

@interface MediaFullScreenViewController : UIViewController

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIImageView *imageView;

- (instancetype) initWIthMedia:(Media *)media;

- (void) centerScrollView;

@end