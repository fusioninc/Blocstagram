//
//  ImageLibraryViewController.h
//  Blocstagram
//
//  Created by Fusion on 8/14/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ImageLibraryViewController;

@protocol ImageLibraryViewControllerDelegate <NSObject>

- (void)ImageLibraryViewController:(ImageLibraryViewController *)ImageLibraryViewController didCompleteWithImage:(UIImage *)image;

@end

@interface ImageLibraryViewController : UICollectionViewController

@property (nonatomic, weak) NSObject <ImageLibraryViewControllerDelegate> *delegate;

@end
