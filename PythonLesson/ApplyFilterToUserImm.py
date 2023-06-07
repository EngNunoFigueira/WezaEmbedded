import xml.etree.ElementTree as ET

print ("At this tutorial we training the way Python manager XML files")

# Load the Imm xml to from the disc
tree = ET.parse('/media/nundelTech/PythonLesson/sapcXmlUserAccount.xml')
immXMLDestination = tree.getroot()

tree = ET.parse('/media/nundelTech/PythonLesson/FileXmlToTest.xml')
immXMLSource = tree.getroot()

# SAPC 1.3 update: this functions will be used to ensure that all default CustomRole, CustomRule and Users does not be migrate to the destination.	 
def remove_default_secm_elements_from_source_dom(fileXmlsource,xml_tag,cond_parameter=None,option_parameter=None):  
    if option_parameter is not None:
        print ("Vai a merda...")



def TTTTdont_migrate_sec_elements_existing_in_destination_sapc (sec_source_element):
    toDelete=False
    for userSource in immXMLSource.iter('userAccountId'):
        accountSourceName=userSource.text
        for userDest in immXMLDestination.iter('userAccountId'):
            accountDestName=userDest.text
            if accountDestName == accountSourceName:
               toDelete=True
    return toDelete



#for users in immXMLSource.iter('UserAccount'): 
	#for AccountId in users.findall('userAccountId'):
	    #print (AccountId.text)
	    #if AccountId.text == "systemreadonly":
	    	#users.remove(AccountId)
	    	#tree.write('/media/nundelTech/PythonLesson/FileXmlToTest.xml')  
#print(ET.tostring(immXMLSource))


def dont_migrate_sec_elements_if_existing_in_destination_sapc (sec_source_element):
    for users in immXMLSource.findall('UserAccount'):
        userName = (users.find('userAccountId').text)
        print (userName)
        if userName == sec_source_element:
           immXMLSource.remove(users)
           tree.write('/media/nundelTech/PythonLesson/FileXmlToTest.xml')  
   

print ("Main program")
dont_migrate_sec_elements_if_existing_in_destination_sapc('sapcoperator')


#------------------------------------------------- upgrade by replacement --------------------------------------------#

#SAPC 1.3 update: select the CustomRole, CustomRule and Users that will not be migrated to the destination.
    def element_exists_in_destination(source_dom_element, destination_dom_element, xml_tag, name_tag):
        for list_of_destination_dom_elements in destination_dom_element.findall('.//' + xml_tag + '/..'):
            for dom_element in list_of_destination_dom_elements.findall(xml_tag):
                for child in dom_element:
                    if child.tag == name_tag:
                        if with_child_tagname(source_dom_element, child.text, name_tag):
                            return True
        return False
#------------------------------------------------- Second function -------- ------------------------------------------#

    def with_child_tagname(element, value, name_tag):
        for child in element:
            if child.tag == name_tag and child.text.startswith(value):
                return True
        return False
#-------------------------------------------------------end-----------------------------------------------------------#