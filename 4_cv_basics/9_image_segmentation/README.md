# Image Segmentation using GrabCut Algorithm


## Table of Contents

1. [Introduction](#introduction)
2. [Basics of Image Segmentation](#basics-of-image-segmentation)
3. [Graph Cuts in Image Segmentation](#graph-cuts-in-image-segmentation)
4. [How GraphCut Works](#how-graphcut-works)
5. [How to Use This Project](#how-to-use-this-project)


# Image Segmentation
## Introduction

Image segmentation allows devices to identify individual items in images. Consequently, apps can change backgrounds or erase subjects because of this capability. This process in a computer allows machines to isolate different elements that exist in an image.

When people look at photos, they automatically segment people, objects, and backgrounds without even realizing it. Brains automatically detect edges between objects. Image segmentation allows computers to do the same so that they can segment couches from cats, people from sunsets, or tables from apples.

![Image Segregation](assets/segregated.jpeg "")



## Basics of Image Segmentation

Glancing at a family photograph, the human vision instinctively recognizes individual family members, furniture pieces, pets, and other things in the photograph. The human vision recognizes those things naturally.

Computers view images differently. An image is just a collection of colored pixels to a computer. Image segmentation assists computers in making sense of these pixels by grouping them into significant areas. The process is like viewing a mosaic at different distances. Close up, only single pieces of the mosaic are observed. Middle distance, there are patterns. Distant, the whole picture is visible. Segmentation allows computers to view the big picture rather than single pixels.

Simple segmentation merely clumps pixels of the same color (like blue pixels that may be defining sky). More advanced techniques detect abrupt color transitions that define edges (like the edge of a person). The most advanced techniques identify objects by shape and context.


![how individual pixels become grouped regions](assets/pixels_grouping.jpeg "")


## Graph Cuts in Image Segmentation
Graph cuts are a powerful image segmentation tool. Although the term is technical, the idea is simple.

A picture can be imagined as a neighborhood where there is a house for every pixel. Every house shares a common border with its neighboring houses (neighbor pixels). There are two community centers for the neighborhood - one for "foreground" people and another one for "background" people.

Each home has paths to both centers. More substantial paths are for stronger connections. More vibrant red houses may have stronger connections to the "foreground" center when trying to find a red apple in a picture.

The task is to determine where to place a wall in this neighborhood, splitting the two populations in front and rear. The objective is to not cut across main thoroughfares as much as possible. This wall is the border of the object and the background.

This approach has the following advantages:

- Examines the entire image as a whole rather than individual pixels
- Both pixel characteristics and neighboring pixel interactions are evaluated 
- Allows people to contribute, such as labelling some areas as foreground.


## How GrabCut Works
GrabCut is an easy-to-use separator for image parts. Here's how it functions:

- Rectangle Selection: Users put a rectangle over the subject to be separated. The rectangle says "the subject is somewhere in this area." Everything outside of this rectangle automatically becomes the background.
- Color Analysis: The system processes color patterns in both possible foreground (within the rectangle) and certain background (beyond the rectangle). For instance, while choosing a golden retriever, the system can determine tan/gold colors as possible foreground and green grass colors as background.
- Building a Connection Network: The system constructs a network of relationships between all the pixels with foreground or background probability based on color. Visually similar pixels link to one another.
Boundary Determination: It determines the most natural boundary line between the foreground and background. It detects the shortest path in the image that separates the object from the surrounding objects. - Iterative Refinement: Once estimated, the system improves its knowledge of foreground and background colors, and then recalculates. The process is repeated a number of times until generating optimal results.

GrabCut allows users to intervene when errors occur. If an area of the subject is not chosen, users can mark that region as clear foreground. Similarly, regions of the background that were incorrectly added can be designated as clear background. This combines human decisions with computer processing.



![how individual pixels become grouped regions](assets/user_defining_roi.jpeg "")


GrabCut has other functionality:
- Definite Region Marking: Regions may be marked as "definitely foreground" or "definitely background" - to keep some things in or out.
- Multi-Object Processing: Later releases of GrabCut process multiple objects simultaneously, allowing for single object detection of each subject in group images.
- Texture Recognition: New GrabCut methods take into account textures, rather than colors. This helps in identifying visually similar objects with different patterns.
- Video Processing: GrabCut is extended to video applications, following subjects between frames. The system uses knowledge from past frames to inform current frames.
- Multi-level Processing: Advanced systems process at a variety of levels of detail at once - considering both broad and detailed views of images to identify the general shape and detailed features.
These abilities transform GrabCut from a simple selection tool into an all-around assistant for anything from easy photo editing to advanced visual analysis.

## How to Use This Project


### 1. Build the Program

```bash
make build SRC=src/main.cpp
```

### 2. Run the Program

```bash
./image_segmentation
```

### 3. Instructions

- The default image (`cat1.jpeg`) is loaded.
- A window will appear showing the image.
- Draw a rectangle around the object using the mouse.
- The program applies GrabCut to extract the foreground object.
- The result is displayed with a clean white background.

### 4. Clean the Build

```bash
make clean src
```
