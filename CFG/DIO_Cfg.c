#include "MemMap.h"
#include "StdTupes.h"
#include "Utils.h"

#include "DIO_interface.h"
#include "DIO_Cfg.h"
#include "DIO_private.h"

const  DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS]=
{
	INFREE,     /*PORT A PIN 0 */
	INFREE,     /*PORT A PIN 1 */
	OUTPUT,     /*PORT A PIN 2 */
	OUTPUT,     /*PORT A PIN 3 */
	OUTPUT,     /*PORT A PIN 4 */
	OUTPUT,     /*PORT A PIN 5 */
	OUTPUT,     /*PORT A PIN 6 */
	INFREE,     /*PORT A PIN 7 */
	OUTPUT,     /*PORT B PIN 0 */
	OUTPUT,     /*PORT B PIN 1 */
	OUTPUT,     /*PORT B PIN 2 */
	OUTPUT,     /*PORT B PIN 3 */ 
	OUTPUT,     /*PORT B PIN 4 */
	OUTPUT,     /*PORT B PIN 5 mosi */
	INFREE,     /*PORT B PIN 6 MISO */
	OUTPUT,     /*PORT B PIN 7 CLK*/
	OUTPUT,     /*PORT C PIN 0 */
	OUTPUT,     /*PORT C PIN 1 */
	OUTPUT,     /*PORT C PIN 2 */
	OUTPUT,     /*PORT C PIN 3 */
	OUTPUT,     /*PORT C PIN 4 */
	OUTPUT,     /*PORT C PIN 5 */
	OUTPUT,     /*PORT C PIN 6 */
	OUTPUT,     /*PORT C PIN 7 */
	INFREE,     /*PORT D PIN 0 */
	OUTPUT,     /*PORT D PIN 1 */
	INFREE,     /*PORT D PIN 2 */
	INPULL,     /*PORT D PIN 3 */
	OUTPUT,     /*PORT D PIN 4 */ 
	INPULL,     /*PORT D PIN 5 */ 
	INPULL,     /*PORT D PIN 6 */
	INPULL    /*PORT D PIN 7 */
	};