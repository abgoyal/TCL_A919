

#include "../comedidev.h"
#include <linux/kernel.h>
#include "comedi_pci.h"

#define PCI7230_DI      0x00
#define PCI7230_DO	    0x00

#define PCI_DEVICE_ID_PCI7230 0x7230

static DEFINE_PCI_DEVICE_TABLE(adl_pci7230_pci_table) = {
	{
		PCI_VENDOR_ID_ADLINK,
		PCI_DEVICE_ID_PCI7230,
		PCI_ANY_ID,
		PCI_ANY_ID,
		0,
		0,
		0
	},
	{0}
};

MODULE_DEVICE_TABLE(pci, adl_pci7230_pci_table);

struct adl_pci7230_private {
	int data;
	struct pci_dev *pci_dev;
};

#define devpriv ((struct adl_pci7230_private *)dev->private)

static int adl_pci7230_attach(struct comedi_device *dev,
	struct comedi_devconfig *it);
static int adl_pci7230_detach(struct comedi_device *dev);
static struct comedi_driver driver_adl_pci7230 = {
	.driver_name = "adl_pci7230",
	.module = THIS_MODULE,
	.attach = adl_pci7230_attach,
	.detach = adl_pci7230_detach,
};

/* Digital IO */

static int adl_pci7230_di_insn_bits(struct comedi_device *dev,
	struct comedi_subdevice *s,
	struct comedi_insn *insn,
	unsigned int *data);

static int adl_pci7230_do_insn_bits(struct comedi_device *dev,
	struct comedi_subdevice *s,
	struct comedi_insn *insn,
	unsigned int *data);

static int adl_pci7230_attach(struct comedi_device *dev,
	struct comedi_devconfig *it)
{
	struct pci_dev *pcidev;
	struct comedi_subdevice *s;
	int bus, slot;

	printk(KERN_INFO "comedi%d: adl_pci7230\n", dev->minor);

	dev->board_name = "pci7230";
	bus = it->options[0];
	slot = it->options[1];

	if (alloc_private(dev, sizeof(struct adl_pci7230_private)) < 0)
		return -ENOMEM;

	if (alloc_subdevices(dev, 2) < 0)
		return -ENOMEM;

	for (pcidev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, NULL);
		pcidev != NULL;
		pcidev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, pcidev)) {

		if (pcidev->vendor == PCI_VENDOR_ID_ADLINK &&
			pcidev->device == PCI_DEVICE_ID_PCI7230) {
			if (bus || slot) {
				/* requested particular bus/slot */
				if (pcidev->bus->number != bus ||
					PCI_SLOT(pcidev->devfn) != slot) {
					continue;
				}
			}
			devpriv->pci_dev = pcidev;
			break;
		}
	}
	if (pcidev == NULL) {
		printk(KERN_ERR "comedi%d: no supported board found! (req. bus/slot : %d/%d)\n",
			dev->minor, bus, slot);
		return -EIO;
	}
	if (comedi_pci_enable(pcidev, "adl_pci7230") < 0) {
		printk(KERN_ERR "comedi%d: Failed to enable PCI device and request regions\n",
			dev->minor);
		return -EIO;
	}
	dev->iobase = pci_resource_start(pcidev, 2);
	printk(KERN_DEBUG "comedi: base addr %4lx\n", dev->iobase);

	s = dev->subdevices + 0;
	/* Isolated do */
	s->type = COMEDI_SUBD_DO;
	s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
	s->n_chan = 16;
	s->maxdata = 1;
	s->range_table = &range_digital;
	s->insn_bits = adl_pci7230_do_insn_bits;

	s = dev->subdevices + 1;
	/* Isolated di */
	s->type = COMEDI_SUBD_DI;
	s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON;
	s->n_chan = 16;
	s->maxdata = 1;
	s->range_table = &range_digital;
	s->insn_bits = adl_pci7230_di_insn_bits;

	printk(KERN_DEBUG "comedi: attached\n");

	return 1;
}

static int adl_pci7230_detach(struct comedi_device *dev)
{
	printk(KERN_DEBUG "comedi%d: pci7230: remove\n", dev->minor);

	if (devpriv && devpriv->pci_dev) {
		if (dev->iobase)
			comedi_pci_disable(devpriv->pci_dev);
		pci_dev_put(devpriv->pci_dev);
	}

	return 0;
}

static int adl_pci7230_do_insn_bits(struct comedi_device *dev,
	struct comedi_subdevice *s,
	struct comedi_insn *insn,
	unsigned int *data)
{
	if (insn->n != 2)
		return -EINVAL;

	if (data[0]) {
		s->state &= ~data[0];
		s->state |= (data[0] & data[1]);

		outl((s->state  << 16) & 0xffffffff, dev->iobase + PCI7230_DO);
	}

	return 2;
}

static int adl_pci7230_di_insn_bits(struct comedi_device *dev,
	struct comedi_subdevice *s,
	struct comedi_insn *insn,
	unsigned int *data)
{
	if (insn->n != 2)
		return -EINVAL;

	data[1] = inl(dev->iobase + PCI7230_DI) & 0xffffffff;

	return 2;
}

COMEDI_PCI_INITCLEANUP(driver_adl_pci7230, adl_pci7230_pci_table);
