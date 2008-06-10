
/****************************************************************************
 *
 * $Id: test1394TwoGrabber.cpp,v 1.2 2008-06-10 14:37:08 asaunier Exp $
 *
 * Copyright (C) 1998-2008 Inria. All rights reserved.
 *
 * This software was developed at:
 * IRISA/INRIA Rennes
 * Projet Lagadic
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * http://www.irisa.fr/lagadic
 *
 * This file is part of the ViSP toolkit
 *
 * This file may be distributed under the terms of the Q Public License
 * as defined by Trolltech AS of Norway and appearing in the file
 * LICENSE included in the packaging of this file.
 *
 * Licensees holding valid ViSP Professional Edition licenses may
 * use this file in accordance with the ViSP Commercial License
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Contact visp@irisa.fr if any conditions of this licensing are
 * not clear to you.
 *
 * Description:
 * Firewire cameras video capture.
 *
 * Authors:
 * Fabien Spindler
 *
 *****************************************************************************/


/*!
  \file test1394TwoGrabber.cpp

  \brief  Aquire images using libdc1394-2.x library.

*/

#include <iostream>



#include <visp/vpConfig.h>
#include <visp/vpDebug.h>

#if defined(VISP_HAVE_DC1394_2)

#include <visp/vp1394TwoGrabber.h>
#include <visp/vpImageIo.h>
/*!
  \example test1394TwoGrabber.cpp



*/
int
main()
{
  try  {
    std::cout << "IEEE1394 test in progress..." << std::endl;

    // Creation of an empty image container
    vpImage<unsigned char> I;

    // Creation of a framegrabber
    vp1394TwoGrabber g;
    for (int i=0;i<10;i++) g.acquire(I);
    g.close();
    vpImageIo::write(I,"/tmp/$USER/imagetest1.pgm");

    std::cout << "New connection..."<< std::endl;
    g.open(I);
    g.close();

    std::cout << "New connection..."<< std::endl;
    g.open(I);
    //g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_800x600_YUV422);
    g.acquire(I);
    g.close();
    vpImageIo::write(I,"/tmp/$USER/imagetest2.pgm");
  }
  catch (...) {
    vpCERROR << "Failure: exit" << std::endl;
  }
}
#else
int
main()
{
  vpTRACE("Ieee 1394 grabber capabilities are not available...\n"
          "You should install libdc1394-2 to use this binary.") ;
}

#endif

/*
 * Local variables:
 * c-basic-offset: 2
 * End:
 */
