//
//  CameraViewController.h
//  Blocstagram
//
//  Created by Fusion on 8/12/15.
//  Copyright (c) 2015 Jason Kuang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CameraViewController;

@protocol CameraViewControllerDelegate <NSObject>

- (void)cameraViewController:(CameraViewController *)cameraViewController didCompleteWithImage:(UIImage *)image;

@end

@interface CameraViewController : UIViewController


//A delegate property and accompanying protocol will inform the presenting view controller when the camera view controller is done.
@property (nonatomic, weak) NSObject <CameraViewControllerDelegate> *delegate;

@end
