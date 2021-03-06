//
//  SCNJavascript.h
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

#if JSC_OBJC_API_ENABLED

/*
 @function SCNExportJavaScriptModule
 @abstract Exports SceneKit's symbols (constants and class definition) into the specified JavaScript context.
 @discussion SceneKit's classes, properties and constants are exported as global object with their original name. Selectors are exported using the rules defined in JavaScriptCore's JSExport.h.
 
 For example to instanciate a node in JavaScript:
 
 var aNode = SCNNode.node();
 
 to change its opacity:
 
 aNode.opacity = 0.5;
 
 to remove from its parent node:
 
 aNode.removeFromParentNode();
 
 to animate a node opacity:
 
 SCNTransaction.begin();
 SCNTransaction.setAnimationDuration(1.0);
 aNode.opacity = 0.5;
 SCNTransaction.commit();
 
 The following special objects are also exported:
 
 class name           constructor                                                  Objective-C class
 SCNColor             SCNColor.color(r,g,b,a)                                      NSColor
 SCNTimingFunction    SCNTimingFunction.functionWithName(name)                     CATimingFunction
 SCNBasicAnimation    SCNBasicAnimation.basicAnimationWithKeyPath(aPath)           CABasicAnimation
 SCNAnimationGroup    SCNAnimationGroup.animationGroup()                           CAAnimationGroup
 SCNKeyframeAnimation SCNKeyframeAnimation.keyframeAnimationWithKeyPath(aPath)     CAKeyframeAnimation
 SCNImage             SCNImage.imageWithURL(aURL)                                  NSImage / UIImage
                      SCNImage.imageWithPath(aPath)                                  
 
 Vectors use this syntax:
 aNode.scale = {x:2, y:2, z:2};
 
 Matrices use this syntax:
 aNode.transform = {m11:1, m12:0, m13:0 ... m44:1};
 */

SCN_EXTERN void SCNExportJavaScriptModule(JSContext *context);

#endif
